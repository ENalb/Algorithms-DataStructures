#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

template <typename T>
class Queue{
public:
	Queue();
	~Queue();
	void enqueue(const T& val);
	void dequeue();
	bool empty();
	T& peek();
private:
	List<T> items;
};

#include "queue.tpp"

#endif