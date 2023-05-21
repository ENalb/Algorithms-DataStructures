#include "stack.h"
#include "vector.h"
#include <stdexcept>

template <typename T>
Stack<T>::Stack() : top{-1} {}

template <typename T>
bool Stack<T>::empty(){
	return top == -1;
}

template <typename T>
void Stack<T>::push(const T& val){
	if(top >= items.size()){
		throw std::out_of_range{"Stack is full"};
	}
	top++;
	items.push_back(val);
}

template <typename T>
void Stack<T>::pop(){
	if(empty()){
		throw std::out_of_range{"Stack is empty"};
	}
	items.pop_back();
	top--;
}

template <typename T>
T Stack<T>::peek(){
	if(empty()){
		throw std::out_of_range{"Stack is full"};
	}
	return items.back();
}