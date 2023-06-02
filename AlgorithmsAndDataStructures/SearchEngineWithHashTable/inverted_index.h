#include "d_list.h"
#include "hashtable.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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

class SearchEngine{
public:
	SearchEngine() = default;
	void loadDictionary(const std::string& filename){
		std::ifstream file(filename);
		std::string word;
		while(file >> word){
			dictionary.push_back(word);
		}
		file.close();
	}
	void addDocument(const std::string& document){
		std::ifstream file(document);
	    	std::string word;
	    	while (file >> word) {
	        	std::string normalized = normalizeWord(word);
	        		if (!normalized.empty()) {
	            			Pair<std::string, List<std::string>>& pair = invertedIndex[normalized];
	            			List<std::string>& documentList = pair.getValue();
	            			if(documentList.find(document) == -1){
	            				documentList.push_back(document);
	            			}
	            			continue;
	        		}
	    	}	
	    	file.close();
	}
	void saveIndex(const std::string& filename) {
	    	std::ofstream file(filename);
	    	const auto& hashTable = invertedIndex.getHashTable();
	    	for (size_t i = 0; i < hashTable.size(); i++) {
	    		try{
	    			const auto& pair = hashTable[i];
		        	if (!pair.isEmpty()) {
		            		const auto& key = pair.getKey();
		            		const auto& value = pair.getValue();
		            		file << key << ": ";
		            		for (int j = 0; j < value.size(); j++) {
		                		file << value[j];
		                		if (j != value.size() - 1) {
		                    			file << " -> ";
		                		}
		            		}
		            		file << std::endl;
		        	}
	    		}
	        	catch (const std::out_of_range& e){
	        		std::cout << "No index: " << std::endl;
	        	}
	    	}
	    	file.close();
	}
	void searchWord(const std::string& word) {
	    	std::ifstream file("db.txt");
	    	std::string line;
	    	bool found = false;

	    	while (std::getline(file, line)) {
	        	if (line.find(word) != std::string::npos) {
	            		found = true;
	            		std::cout << "Results for word: " << word << std::endl;
	            		std::cout << line << std::endl;
	            		break;
	        	}
	    	}

	    	if (!found) {
	        	std::cout << "No results found for word: " << word << std::endl;
	    	}

	    	file.close();
	}
private:
	HashTable<std::string, List<std::string>> invertedIndex{10000};
	std::vector<std::string> dictionary;
	std::string cleanWord(const std::string& w) {
		std::string cleaned;
	    	for (char c : w) {
	        	if (std::isalpha(c)) {
	            		cleaned += std::tolower(c);
	        	}
	    	}
	    	return cleaned;
	}
	std::string normalizeWord(const std::string& w) {
	    	std::string cleanedWord = cleanWord(w);
	    	int index = binarySearch(dictionary, cleanedWord);
	    	if (index != -1) {
	        	return dictionary[index];
	    	}
	    	return "";
	}
};
