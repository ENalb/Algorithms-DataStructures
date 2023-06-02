#include "inverted_index.h"
#include <iostream>
#include <fstream>

int main(){
	SearchEngine searchEngine;
	searchEngine.loadDictionary("words_alpha.txt");
	searchEngine.addDocument("1.txt");
	searchEngine.addDocument("2.txt");
	searchEngine.saveIndex("db.txt");
	searchEngine.searchWord("algorithm");
	searchEngine.searchWord("lorem");

	return 0;
}