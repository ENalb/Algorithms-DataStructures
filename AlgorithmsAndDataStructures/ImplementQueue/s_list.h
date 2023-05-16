#ifndef LIST_H
#define LIST_H

class List{
public:
	List() : head{nullptr}, tail{nullptr} {}
	~List();
	void push_front(int val);
	void push_back(int val);
	void pop_front();
	void pop_back();
	bool empty();
	int& front();
	int& back();
	void remove(int value);
	int size() const;
private:
	struct Node {
	    int val;
	    Node* next;
	    Node(int x) : val{x}, next{nullptr} {}
	};
	Node* head;
	Node* tail;
};

#endif