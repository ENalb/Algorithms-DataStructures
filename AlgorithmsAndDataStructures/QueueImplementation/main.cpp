#include <iostream>
#include "queue.h"

int main(){
	Queue<int> queue;
	std::cout << "Is queue empty? " << std::boolalpha << queue.empty() << std::endl;
	queue.enqueue(25);
	std::cout << "Is queue empty? " << std::boolalpha << queue.empty() << std::endl;
	queue.enqueue(37);
	queue.enqueue(14);
	std::cout << "First element: " << queue.peek() << std::endl;
	queue.dequeue();
	std::cout << "First element: " << queue.peek() << std::endl;
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();

	return 0;
}