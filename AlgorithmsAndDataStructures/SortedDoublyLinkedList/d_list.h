#ifndef D_LIST_H
#define D_LIST_H

#include <string>

template <typename T>
class List{
public:
	List() : head{nullptr}, tail{nullptr} {}
	~List();
	void push_front(const T& val);
	void push_back(const T& val);
	void pop_front();
	void pop_back();
	bool empty();
	T& front();
	T& back();
	void remove(const T& value);
	int size() const;
	void erase(int pos);
	void insert(int pos, const T& val);
	void sortedInsert(const T& val);
	int find(const T& val);
	void printList();
	void inputList(int size);
	typename List<T>::Node* merge(typename List<T>::Node* left, typename List<T>::Node* right);
	typename List<T>::Node* mergeSort(typename List<T>::Node* head);
	void mergeSort();
	void serialize(const std::string& filename);
	List<T> deserialization(const std::string& filename);
private:
	struct Node {
	    T val;
	    Node* next;
	    Node* prev;
	    Node(T x) : val{x}, next{nullptr}, prev{nullptr} {}
	};
	Node* head;
	Node* tail;
};

#include "d_list.tpp"

#endif