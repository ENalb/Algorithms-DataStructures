#include "s_list.h"

class Queue{
public:
	Queue() : list() {}
	void enqueue(int x);
	void dequeue();
	int front();
	int back();
	bool empty();
	int size();
private:
	List list;
};