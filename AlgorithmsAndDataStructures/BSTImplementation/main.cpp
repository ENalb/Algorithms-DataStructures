#include <iostream>
#include "bst.h"

int main(){
	BinarySearchTree<int> bst;
	std::cout << "Is tree empty? " << std::boolalpha << bst.isEmpty() << std::endl;
	bst.add(5);
	bst.add(7);
	bst.add(1);
	bst.add(12);
	bst.add(105);
	bst.printInorder();
	std::cout << "Height - " << bst.getHeight() << std::endl;
	std::cout << "Nodes - " << bst.getNumberOfNodes() << std::endl;
	std::cout << "Root data - " << bst.getRootData() << std::endl;
	bst.setRootData(6);
	std::cout << "Root data - " << bst.getRootData() << std::endl;
	std::cout << "Min value - " << bst.getMin() << std::endl;
	std::cout << "Max value - " << bst.getMax() << std::endl;
	std::cout << "Get entry - " << bst.getEntry(1) << std::endl;
	bst.printInorder();
	std::cout << "Is tree contains 7? " << std::boolalpha << bst.containsIterative(7) << std::endl;
	std::cout << "Is tree contains 36? " << std::boolalpha << bst.contains(36) << std::endl;
	bst.remove(12);
	bst.printInorder();
	std::cout << "Successor of 7 " << bst.getSuccessor(7) << std::endl;
	std::cout << "Predecessor of 6 " << bst.getPredecessor(6) << std::endl; 
	bst.printPreorder();
	std::cout << std::endl;
	bst.printPostorder();
	std::cout << std::endl;

	return 0;
}