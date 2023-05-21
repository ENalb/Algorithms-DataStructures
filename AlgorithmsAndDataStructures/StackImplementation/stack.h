#ifndef STACK_H
#define STACK_H

#include "vector.h"

template <typename T>
class Stack{
public:
	Stack();
	bool empty();
	void push(const T& val);
	void pop();
	T peek();
private:
	int top;
	Vector<T> items;
};

#include "stack.tpp"

#endif