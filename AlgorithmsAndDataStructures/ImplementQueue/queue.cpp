#include "queue.h"
#include <stdexcept>

void Queue::enqueue(int x){
	list.push_back(x);
}

void Queue::dequeue(){
	if(empty()){
		throw std::out_of_range{"Queue is empty"};
	}
	list.pop_front();
}

int Queue::front(){
	return list.front();
}

int Queue::back(){
	if(empty()){
		throw std::out_of_range{"Queue is empty"};
	}
	return list.back();
}

bool Queue::empty(){
	if(list.empty()){
		return true;
	}
	return false;
}

int Queue::size(){
	return list.size();
}