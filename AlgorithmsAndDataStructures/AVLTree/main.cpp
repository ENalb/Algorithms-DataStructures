#include "avl_tree.h"
#include <iostream>

int main(){
	AVL<int> tree;
	std::cout << tree.getHeight() << std::endl;
	tree.insert(10);
	std::cout << tree.getHeight() << std::endl;
	tree.insert(20);
	std::cout << tree.getHeight() << std::endl;
	tree.insert(30);
	std::cout << tree.getHeight() << std::endl;
	tree.inorderTraversal();
	std::cout << std::endl;
	tree.preorderTraversal();
	std::cout << std::endl;
	tree.postOrderTraversal();
	std::cout << std::endl;
	std::cout << std::boolalpha << tree.find(20) << std::endl;
	std::cout << std::boolalpha << tree.find(40) << std::endl;
	tree.remove(10);
	tree.inorderTraversal();
	std::cout << std::endl;
}