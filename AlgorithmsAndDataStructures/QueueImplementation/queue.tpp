#include "queue.h"
#include <stdexcept>

template <typename T>
Queue<T>::Queue() = default;

template <typename T>
Queue<T>::~Queue() = default;

template <typename T>
void Queue<T>::enqueue(const T& val){
	items.push_back(val);
}

template <typename T>
void Queue<T>::dequeue(){
	if(empty()){
		throw std::out_of_range{"List is empty:"};
	}
	items.pop_front();
}

template <typename T>
bool Queue<T>::empty(){
	return items.empty();
}

template <typename T>
T& Queue<T>::peek(){
	return items.front();
}