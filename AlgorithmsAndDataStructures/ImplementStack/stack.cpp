#include "stack.h"

void Stack::push(int x){
	++top_index;
    arr.resize(top_index + 1);
    arr[top_index] = x;
}

void Stack::pop(){
	if(empty()){
		throw std::out_of_range{"Stack is empty"};
	}
	--top_index;
}

int Stack::top(){
	if(empty()){
		throw std::out_of_range{"Stack is empty"};
	}
	return arr[top_index];
}

bool Stack::empty(){
	return top_index == -1;
}

int Stack::size(){
	return top_index + 1;
}