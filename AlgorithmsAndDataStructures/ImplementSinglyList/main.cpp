#include "s_list.h"
#include <iostream>

int main(){
	List mylist;
	mylist.push_back(5);
	mylist.push_back(15);
	mylist.push_back(64);
	std::cout << mylist.size() << std::endl;
	std::cout << mylist.front() << std::endl;
	std::cout << mylist.back() << std::endl;
	mylist.push_front(17);
	std::cout << mylist.front() << std::endl;
	mylist.pop_back();
	std::cout << mylist.back() << std::endl;
	mylist.pop_front();
	std::cout << mylist.front() << std::endl;
	std::cout << mylist.empty() << std::endl;
	mylist.remove(5);
	std::cout << mylist.front() << std::endl;

	return 0;
}