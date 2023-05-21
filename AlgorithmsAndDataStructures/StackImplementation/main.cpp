#include <iostream>
#include "stack.h"

int main(){
	Stack<int> stack;
	std::cout << "Is stack empty? " << std::boolalpha << stack.empty() << std::endl;
	stack.push(6);
	std::cout << "Is stack empty? " << std::boolalpha << stack.empty() << std::endl;
	stack.push(9);
	stack.push(12);
	std::cout << "Last element: " << stack.peek() << std::endl;
	stack.pop();
	std::cout << "Last element: " << stack.peek() << std::endl;
	stack.pop();
	stack.pop();
	stack.pop();

	return 0;
}