#include <iostream>
#include "list.h"

int main(){
	List<int> list;
	list.push_back(9);
	list.push_back(14);
	list.push_back(68);
	list.printList();
	list.sortedInsert(65);
	list.printList();
	list.sortedInsert(-8);
	list.printList();
	list.sortedInsert(147);
	list.printList();
	list.sortedInsert(12);
	list.printList();
	list.serialization("sortedList.txt");
	List<int> newList = list.deserialization("sortedList.txt");
	newList.printList();

	return 0;
}