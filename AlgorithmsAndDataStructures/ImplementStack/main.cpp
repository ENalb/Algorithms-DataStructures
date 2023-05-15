#include "stack.h"
#include <iostream>

int main(){
	Stack stack;
	stack.push(7);
	stack.push(6);
	stack.push(1);
	std::cout << stack.empty() << std::endl;
	std::cout << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.top() << std::endl;
	std::cout << stack.size() << std::endl;
	stack.pop();
	stack.pop();
	std::cout << stack.size() << std::endl;
	std::cout << stack.empty() << std::endl;
	stack.pop();

	return 0;
}