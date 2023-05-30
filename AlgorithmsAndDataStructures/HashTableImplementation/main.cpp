#include "hashtable.h"
#include <iostream>
#include <string>

int main(){
	HashTable<std::string, int> ht(10000);
	ht.insert("Emi", 22);
	ht.insert("Nalbandyan", 21);
	ht.insert("EN", 15);
	std::cout << ht.find("Emi") << std::endl;
	std::cout << ht.find("Nalbandyan") << std::endl;
	std::cout << ht.find("EN") << std::endl;
	ht.remove("EN");
	std::cout << ht.find("EN") << std::endl;
	std::cout << ht.find(21) << std::endl;
	std::cout << ht.find(15) << std::endl;

	return 0;
}