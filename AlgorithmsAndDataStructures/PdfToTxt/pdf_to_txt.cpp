#include "pdf_to_txt.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>

PdfToTxt::PdfToTxt() = default;

PdfToTxt::PdfToTxt(const std::string& p) : path{p} {}

void PdfToTxt::readPdf() {
    try {
        auto document = poppler::document::load_from_file(path);
        if (!document || document->is_locked()) {
            std::cout << "Failed to open or process the PDF file." << std::endl;
            return;
        }
        int numPages = document->pages();
        for (int i = 0; i < numPages; ++i) {
            auto page = document->create_page(i);
            if (!page) {
                std::cout << "Failed to create page " << i << std::endl;
                continue;
            }
            std::string text;
            auto textBytes = page->text();
            for (auto byte : textBytes) {
                text += static_cast<char>(byte);
            }
            std::istringstream iss(text);
            std::string word;
            while (iss >> word) {
                extractedText.push_back(word);
            }
        }
        std::cout << "Text extracted successfully." << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "An exception occurred: " << e.what() << std::endl;
    }
}

std::string PdfToTxt::normalizeWord(const std::string& word) {
	std::string normalized = "";
	for (int i = 0; i < word.size(); ++i) {
		if (std::isalpha(word[i])) {
			char lowercase = std::tolower(word[i]);
			normalized += lowercase;
		}
	}
	if (normalized.size() > 1 && normalized.back() == 's') {
        normalized.pop_back();
    }
	return normalized;
}

std::vector<std::string> PdfToTxt::normalizedVector() {
	std::vector<std::string> normalizedVec;
	for (int i = 0; i < extractedText.size(); ++i) {
		normalizedVec.push_back(normalizeWord(extractedText[i]));
	}
	return normalizedVec;
}

std::vector<std::string> PdfToTxt::dictionary(const std::string& dictionaryFile) {
	std::ifstream file(dictionaryFile);
	if (!file.is_open()) {
		std::cout << dictionaryFile << " file can't open." << std::endl;
	}
	std::vector<std::string> dict;
	std::string line;
	while (std::getline(file, line)) {
		dict.push_back(line);
	}
	file.close();
	return dict;
}

bool PdfToTxt::checkWordInDictionary(const std::string& word, const std::string& dictionaryFile) {
	std::vector<std::string> vec = dictionary(dictionaryFile);
    std::string normalized = normalizeWord(word);
    for (const std::string& dictWord : vec) {
        if (normalizeWord(dictWord) == normalized) {
            return true;
        }
    }
    return false;
}

void PdfToTxt::writeInTxt(const std::string& fileName) {
	std::ofstream file(fileName);
	if (!file.is_open()) {
		std::cout << "Can't open file " << fileName << std::endl;
		return;
	}
	std::vector<std::string> normalizedVec = normalizedVector();
	std::vector<std::string> uniqueWords;
	for (int i = 0; i < normalizedVec.size(); ++i) {
		if (checkWordInDictionary(normalizedVec[i], "words_alpha.txt")) {
			if (std::find(uniqueWords.begin(), uniqueWords.end(), normalizedVec[i]) == uniqueWords.end()) {
                file << normalizedVec[i] << std::endl;
                uniqueWords.push_back(normalizedVec[i]);
            }
		}
	}
	file.close();
}

void PdfToTxt::setPath(const std::string& p) {
	path = p;
} 

std::string PdfToTxt::getPath() const {
	return path;
}