#include <iostream>
#include <stdexcept>

class Queue{
public:
	Queue() : size{6}, items{new int[size]}, front{-1}, rear{-1} {}
	void enqueue(int val){
		if(full()){
			throw std::out_of_range{"Queue is full"};
		}
		else{
			if(front == -1){
				front = 0;
			}
			rear++;
			items[rear] = val;
		}
	}
	void dequeue(){
		if(empty()){
			throw std::out_of_range{"Queue is empty"};
		}
		else {
	    	if (front == rear) {
	        	front = -1;
	        	rear = -1;
	      	}
	      	else {
	        	front = (front + 1) % size;
	     	}
	    }
	}
	bool full(){
		if(front == 0 && rear == size - 1){
			return true;
		}
		return false;
	}
	bool empty(){
		if(front == -1 && rear == -1){
			return true;
		}
		return false;
	}
	int getFront(){
		return items[front];
	}
	int getFrontIndex(){
		return front;
	}
	int getRear(){
		return items[rear];
	}
	int getRearIndex(){
		return rear;
	}
	~Queue() {
		delete[] items;
		items = nullptr;
	}
private:
	int size;
	int* items;
	int front;
	int rear;
};