#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <map>
#include <algorithm>

std::string readTextFile(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

std::vector<std::string> splitIntoWords(const std::string& text) {
    std::vector<std::string> words;
    std::stringstream ss(text);
    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

std::string cleanWord(const std::string& word) {
    std::string cleaned;
    for (char c : word) {
        if (std::isalpha(c)) {
            cleaned += std::tolower(c);
        }
    }
    return cleaned;
}

int binarySearch(const std::vector<std::string>& wordsAlpha, const std::string& target) {
    int start = 0;
    int end = wordsAlpha.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (wordsAlpha[mid] == target) {
            return mid;
        } 
        else if (target > wordsAlpha[mid]) {
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }
    return -1;
}

std::string normalizeWord(const std::string& word, const std::vector<std::string>& dictionary) {
    std::string lowercaseWord;
    for (char c : word) {
        if (std::isalpha(c)) {
            lowercaseWord += std::tolower(c);
        }
    }
    int index = binarySearch(dictionary, lowercaseWord);
    if (index != -1) {
        return dictionary[index];
    }
    return "";
}

class Word {
public:
    Word(const std::string& w) : word{ w } {}
    std::string getWord() const {
        return word;
    }

private:
    std::string word;
};

class Text {
public:
    void addWord(const std::string& w, const std::vector<std::string>& dictionary) {
        std::string cleanedWord = cleanWord(w);
        std::string normalizedWord = normalizeWord(cleanedWord, dictionary);
        words.push_back(Word(normalizedWord));
    }
    const std::vector<Word>& getWords() const {
        return words;
    }
private:
    std::vector<Word> words;
};

void parseFilesAndStoreResults(const std::vector<std::string>& dictionary) {
    std::map<std::string, std::vector<std::string>> wordToFileMap;
    std::ifstream file1("1.txt");
    std::string word;
    Text text;
    while (file1 >> word) {
        std::string cleanedWord = cleanWord(word);
        if (std::find(wordToFileMap[cleanedWord].begin(), wordToFileMap[cleanedWord].end(), "1.txt") == wordToFileMap[cleanedWord].end()) {
            wordToFileMap[cleanedWord].push_back("1.txt");
        }
        text.addWord(word, dictionary);
    }
    file1.close();
    std::ifstream file2("2.txt");
    while (file2 >> word) {
        std::string cleanedWord = cleanWord(word);
        if (std::find(wordToFileMap[cleanedWord].begin(), wordToFileMap[cleanedWord].end(), "2.txt") == wordToFileMap[cleanedWord].end()) {
            wordToFileMap[cleanedWord].push_back("2.txt");
        }
        text.addWord(word, dictionary);
    }
    file2.close();
    std::ofstream outputFile("db.txt");
    for (const auto& entry : wordToFileMap) {
        outputFile << entry.first << ":";
        for (const std::string& file : entry.second) {
            outputFile << file << ",";
        }
        outputFile.seekp(-1, std::ios_base::end); 
        outputFile << std::endl;
    }
    outputFile.close();
}

void searchWordInDb(const std::string& word) {
    std::ifstream dbFile("db.txt");
    std::string line;
    std::vector<std::string> fileNames;
    while (std::getline(dbFile, line)) {
        std::istringstream iss(line);
        std::string parsedWord;
        std::getline(iss, parsedWord, ':');
        if (parsedWord == word) {
            std::string filePart;
            while (std::getline(iss, filePart, ',')) {
                std::string fileName = filePart.substr(0, filePart.find(':'));
                fileNames.push_back(fileName);
            }
            break;
        }
    }
    if (fileNames.empty()) {
        std::cout << "The word '" << word << "' was not found in any files." << std::endl;
    } 
    else {
        std::cout << "The word '" << word << "' was found in the following files:" << std::endl;
        for (const std::string& fileName : fileNames) {
            std::cout << fileName << std::endl;
        }
    }
}

int main() {
    std::string dictionaryFile = "word_alpha.txt";
    std::vector<std::string> dictionary = splitIntoWords(readTextFile(dictionaryFile));
    parseFilesAndStoreResults(dictionary);
    while (true) {
        std::string searchWord;
        std::cout << "Enter a word to search (or 'q' to quit): ";
        std::cin >> searchWord;
        if (searchWord == "q") {
            break;
        }
        searchWordInDb(searchWord);
    }
    return 0;
}
