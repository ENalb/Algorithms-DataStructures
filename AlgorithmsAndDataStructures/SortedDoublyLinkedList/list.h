#ifndef LIST_H
#define LIST_H

template <typename T>
class List{
public:
	List();
	~List();
	void sortedInsert(const T& value);
	void remove(const T& value);
	void push_back(const T& value);
	void push_front(const T& value);
	void pop_back();
	void pop_front();
	T& front();
	T& back();
	bool empty();
	int size();
	void clear();
	void erase(int position);
	int find(const T& value);
	void printList();
	void serialization(const std::string& filename);
	List<T> deserialization(const std::string& filename);
private:
	struct Node{
		T val;
		Node* next;
		Node* prev;
		Node* nextGreater;
		Node* prevSmaller;
		Node(const T& value) 
			: val{value}, next{nullptr}, prev{nullptr}, nextGreater{nullptr}, prevSmaller{nullptr} {}
	};
	Node* head;
	Node* tail;
};


#include "list.tpp"

#endif