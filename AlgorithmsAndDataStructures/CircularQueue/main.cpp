#include <iostream>
#include "queue.h"

int main(){
	Queue queue;
	std::cout << "Is queue empty? " << std::boolalpha << queue.empty() << std::endl;
	queue.enqueue(17);
	std::cout << queue.getFront() << "-" << queue.getFrontIndex() << std::endl;
	queue.enqueue(25);
	std::cout << queue.getFront() << "-" << queue.getFrontIndex() << std::endl;
	queue.enqueue(165);
	std::cout << "Is queue full? " << std::boolalpha << queue.full() << std::endl;
	queue.enqueue(174);
	queue.enqueue(1);
	queue.enqueue(12);
	std::cout << queue.getRear() << "-" << queue.getRearIndex() << std::endl;
	std::cout << "Is queue full? " << std::boolalpha << queue.full() << std::endl;
	// queue.enqueue(11);
	queue.dequeue();
	std::cout << queue.getFront() << "-" << queue.getFrontIndex() << std::endl;
	std::cout << queue.getRear() << "-" << queue.getRearIndex() << std::endl;
	queue.dequeue();
	std::cout << queue.getFront() << "-" << queue.getFrontIndex() << std::endl;
	std::cout << queue.getRear() << "-" << queue.getRearIndex() << std::endl;
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	std::cout << queue.getFront() << "-" << queue.getFrontIndex() << std::endl;
	std::cout << queue.getRear() << "-" << queue.getRearIndex() << std::endl;
	// queue.dequeue();

}