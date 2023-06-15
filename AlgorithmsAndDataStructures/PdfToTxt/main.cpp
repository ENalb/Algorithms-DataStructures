#include <iostream>
#include "pdf_to_txt.h"

int main() {
	PdfToTxt pdfToTxt("file.pdf");
	pdfToTxt.readPdf();
	pdfToTxt.writeInTxt("output.txt");

	return 0;
}