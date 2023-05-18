#include "d_list.h"
#include <iostream>

int main(){
	List<int> list;
	int size = 0;
	std::cout << "Input list size: ";
	std::cin >> size;
	list.inputList(size);
	list.mergeSort();
	std::cout << "Sorted list:" << std::endl;
	list.printList();
	list.sortedInsert(74);
	list.printList();
	list.sortedInsert(-412);
	list.printList();
	list.sortedInsert(1478);
	list.printList();

	return 0;
}