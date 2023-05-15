#include "array.h"

class Stack{
public:
	Stack() : arr(0), top_index{-1} {};
	void push(int x);
	void pop();
	int top();
	bool empty();
	int size();
private:
	Array arr;
	int top_index;
};