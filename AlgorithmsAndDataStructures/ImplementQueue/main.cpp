#include <iostream>
#include "queue.h"

int main(){
	Queue queue;
	queue.enqueue(3);
	queue.enqueue(14);
	queue.enqueue(69);
	std::cout << "Queue size: " << queue.size() << std::endl;
	std::cout << "Queue first element: " << queue.front() << std::endl;
	std::cout << "Queue last element: " << queue.back() << std::endl;
	queue.dequeue();
	std::cout << "Queue first element: " << queue.front() << std::endl;
	queue.dequeue();
	queue.dequeue();
	std::cout << "Queue size: " << queue.size() << std::endl;
	std::cout << "Empty: " << std::boolalpha << queue.empty() << std::endl;
	queue.dequeue();

	return 0;
}