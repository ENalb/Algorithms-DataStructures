#include "d_list.h"
#include <iostream>
#include <string>

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
	list.serialize("sorted_list.txt");
	List<int> newList = list.deserialization("sorted_list.txt");
	newList.printList();

	return 0;
}