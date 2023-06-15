#ifndef PDF_TO_TXT_H
#define PDF_TO_TXT_H

#include <string>
#include <vector>

class PdfToTxt {
public:
	PdfToTxt();
	PdfToTxt(const std::string&);
	void readPdf();
	std::string normalizeWord(const std::string&);
	std::vector<std::string> normalizedVector();
	std::vector<std::string> dictionary(const std::string&);
	bool checkWordInDictionary(const std::string&, const std::string&);
	void writeInTxt(const std::string&);
	void setPath(const std::string&);
	std::string getPath() const;
private:
	std::string path;
	std::vector<std::string> extractedText;
};

#endif