#include "list.h"
#include <fstream>
#include <string>

template <typename T>
List<T>::List()
	: head{nullptr}, tail{nullptr} 
	{}

template <typename T>
List<T>::~List(){
	clear();
}

template <typename T>
void List<T>::sortedInsert(const T& value) {
	Node* newNode = new Node(value);
	if(head == nullptr){
		head = newNode;
		return;
	}
	Node* prev = nullptr;
    	Node* current = head;
    	while (current && current->val < newNode->val) {
        	prev = current;
        	current = current->next;
    	}
    	if (prev == nullptr) {
        	newNode->next = head;
        	head->prevSmaller = newNode;
        	head = newNode;
    	}
    	else {
        	newNode->next = current;
        	prev->next = newNode;
        	newNode->prevSmaller = prev;
        	if (current)
            		current->prevSmaller = newNode;
        	else
            		tail = newNode;
    	}
}

template <typename T>
void List<T>::remove(const T& value){
	if(head == nullptr){
		return;
	}
	if(head->val == value){
		Node* tmp = head;
		head = head->next;
		delete tmp;
		return;
	}
	Node* curr = head;
    	while(curr->next != nullptr && curr->next->val != value) {
        	curr = curr->next;
    	}
    	if(curr->next == nullptr) {
        	return;
    	}
    	Node* temp = curr->next;
    	curr->next = temp->next;
    	delete temp;
}

template <typename T>
void List<T>::push_back(const T& value){
	Node* newNode = new Node(value);
	newNode->next = nullptr;
	newNode->prev = tail;
	if(tail){
		tail->next = newNode;
	}
	else{
		head = newNode;
	}
	if (newNode->prev) {
        	newNode->prev->nextGreater = newNode;
    	}
	tail = newNode;
}

template <typename T>
void List<T>::push_front(const T& value){
	Node* newNode = new Node(value);
	newNode->next = head;
	if(head){
		head->prev = newNode;
	}
	else{
		tail = newNode;
	}
	if (newNode->next) {
        	newNode->next->prevSmaller = newNode;
    	}
	head = newNode;
}

template <typename T>
void List<T>::pop_back(){
	if(!tail){
		throw std::out_of_range{"List is empty"};
	}
	Node* tmp = tail;
	tail = tail->prev;
	if(tail){
		tail->next = nullptr;
	}
	else{
		head = nullptr;
	}
	if (tmp->prevSmaller != nullptr) {
        	tmp->prevSmaller->nextGreater = nullptr;
    	}
	delete tmp;
}

template <typename T>
void List<T>::pop_front(){
	if(head == nullptr){
		throw std::out_of_range{"List is empty"};
	}
	Node* tmp = head;
	head = head->next;
	if(head != nullptr){
		head->prev = nullptr;
	}
	else{
		tail = nullptr;
	}
	if (tmp->nextGreater != nullptr) {
        	tmp->nextGreater->prevSmaller = nullptr;
    	}
	delete tmp;
}

template <typename T>
T& List<T>::front(){
	if(!head){
		throw std::out_of_range{"List is empty"};
	}
	return head->val;
}

template <typename T>
T& List<T>::back(){
	if(!tail){
		throw std::out_of_range{"List is empty"};
	}
	return tail->val;
}

template <typename T>
bool List<T>::empty(){
	return (size() == 0);
}

template <typename T>
int List<T>::size(){
	Node* current = head;
	int size = 0;
	while(current != nullptr){
		size++;
		current = current->next;
	}
	return size;
}

template <typename T>
void List<T>::clear(){
	Node* current = head;
	while(current != nullptr){
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void List<T>::erase(int position){
	if(empty()){
		throw std::out_of_range{"List is empty"};
	}
	if(position < 0 || position >= size()){
		throw std::out_of_range{"Index out of range"};
	}
	if(position == 0){
		pop_front();
	}
	else if(position == size() - 1){
		pop_back();
	}
	else{
		Node* current = head;
		int count = 0;
        while (count < position) {
            current = current->next;
            count++;
        }

        Node* prevNode = current->prevSmaller;
        Node* nextNode = current->nextGreater;

        prevNode->nextGreater = nextNode;
        nextNode->prevSmaller = prevNode;

        delete current;
	}
}

template <typename T>
int List<T>::find(const T& value){
	Node* current = head;
	int index = 0;
	while(current != nullptr){
		if(current->val == value){
			return index;
		}
		current = current->next;
		index++;
	}
	return index;
}

template <typename T>
void List<T>::printList(){
	Node* current = head;
	while(current != nullptr){
		std::cout << current->val << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

template <typename T>
void List<T>::serialization(const std::string& filename){
	std::ofstream file(filename);
	if(file.is_open()){
		typename List<T>::Node* current = head;
        	while (current != nullptr) {
            		file << current->val << std::endl;
            		current = current->next;
        	}
		file.close();
		std::cout << "Serialization in " << filename << " is done." << std::endl;
	}
	else{
		std::cout << filename << " file doesn't opened." << std::endl;
	}
}

template <typename T>
List<T> List<T>::deserialization(const std::string& filename){
	List<T> sortedList;
	std::ifstream file(filename);
	if(file.is_open()){
		T value;
		while(file >> value){
			sortedList.push_back(value);
		}
		file.close();
		std::cout << "Deserialization from " << filename << " file" << std::endl;
	}
	else{
		std::cout << filename << " file doesn't opened." << std::endl;
	}
	return sortedList;
}
