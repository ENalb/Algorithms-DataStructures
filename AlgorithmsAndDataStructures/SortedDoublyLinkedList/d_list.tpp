#include "d_list.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
List<T>::~List(){
	while(head){
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <typename T>
void List<T>::push_front(const T& val){
	Node* new_node = new Node(val);
	new_node->next = head;
	head = new_node;
	if(!tail){
		tail = head;
	}
}

template <typename T>
void List<T>::push_back(const T& val){
	Node* new_node = new Node(val);
	if(!tail){
		tail = new_node;
		head = tail;
	}
	else{
		tail->next = new_node;
		tail = new_node;
	}
}

template <typename T>
void List<T>::pop_front(){
	if(!head){
		return;
	}
	Node* tmp = head;
	head = head->next;
	if(!head){
		tail = nullptr;
	}
	delete tmp;
}

template <typename T>
void List<T>::pop_back(){
	if(!head){
		return;
	}
	if(head == tail){
		delete head;
		head = nullptr;
		tail = nullptr;
		return; 
	}
	Node* tmp = head;
	while(tmp->next != tail){
		tmp = tmp->next;
	}
	delete tail;
	tail = tmp;
	tail->next = nullptr;
}

template <typename T>
bool List<T>::empty(){
	if(head == nullptr){
		return true;
	}
	return false;
}

template <typename T>
T& List<T>::front(){
	return head->val;
}

template <typename T>
T& List<T>::back(){
	return tail->val;
}

template <typename T>
void List<T>::remove(const T& value){
	if(head == nullptr) {
        	return;
    	}
    	if(head->val == value) {
        	Node* temp = head;
        	head = head->next;
        	delete temp;
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
int List<T>::size() const{
	int count = 0;
	Node* current = head;
	while(current != nullptr){
		count++;
		current = current->next;
	}
	return count;
}

template <typename T>
void List<T>::erase(int pos){
	if(empty()){
		throw std::out_of_range{"List is empty"};
	} 
	if(pos < 0 || pos >= size()){
		throw std::out_of_range{"Index out of range"};
	}
	if(pos == 0){
		pop_front();
	}
	Node* current = head;
    	Node* previous = nullptr;
    	int count = 0;
    
    	while (count < pos) {
		previous = current;
		current = current->next;
		count++;
    	}
    
    	previous->next = current->next;
    
    	if (current == tail) {
        	tail = previous;
    	} 
	else {
        	current->next->prev = previous;
    	}
    
    	delete current;
}

template <typename T>
void List<T>::insert(int pos, const T& val){
	if (pos < 0 || pos > size()) {
        	throw std::out_of_range{"Invalid position"};
    	}
    
    	if (pos == 0) {
        	push_front(val);  
        	return;
    	}
    
    	Node* current = head;
    	Node* previous = nullptr;
    	int count = 0;
    
    	while (count < pos) {
        	previous = current;
        	current = current->next;
        	count++;
    	}
    
    	Node* new_node = new Node(val);
    	new_node->next = current;
    	new_node->prev = previous;
    	previous->next = new_node;
    
    	if (current != nullptr) {
        	current->prev = new_node;
    	} 
	else {
        	tail = new_node;  
    	}
}

template <typename T>
void List<T>::sortedInsert(const T& val){
	Node* newNode = new Node(val);
	if(head == nullptr){
		head = newNode;
		tail = newNode;
	}
	else if(val <= head->val){
		insert(0, val);
	}
	else if(val >= tail->val){
		insert(size(), val);
	}
	else{
		Node* current = head->next;
		while(current != nullptr && current->val < val){
			current = current->next;
		}

		Node* previous = current->prev;
		previous->next = newNode;
		newNode->prev = previous;
		newNode->next = current;
		current->prev = newNode;
	}
}


template <typename T>
int List<T>::find(const T& val){
	Node* current = head;
    	int index = 0;
    	while (current != nullptr) {
        	if (current->val == val) {
            		return index;
        	}
        	current = current->next;
        	index++;
    	}
    	return -1;
}

template <typename T>
void List<T>::printList() {
    	typename List<T>::Node* current = head;

    	while (current != nullptr) {
        	std::cout << current->val << " ";
        	current = current->next;
    	}

    	std::cout << std::endl;
}

template <typename T>
void List<T>::inputList(int size){
	std::cout << "Input list elements values:" << std::endl;
	T input;
	for(int i = 0; i < size; ++i){
		std::cout << "list[" << i << "]->val = ";
		std::cin >> input;
		push_back(input);
	}
	std::cout << std::endl;
}


template <typename T>
typename List<T>::Node* List<T>::merge(typename List<T>::Node* left, typename List<T>::Node* right) {
    	if (left == nullptr)
        	return right;
    	if (right == nullptr)
        	return left;

    	typename List<T>::Node* result = nullptr;

    	if (left->val <= right->val) {
        	result = left;
        	result->next = merge(left->next, right);
        	if (result->next != nullptr)
            		result->next->prev = result;
    		} 
		else {
        		result = right;
        		result->next = merge(left, right->next);
        		if (result->next != nullptr)
            			result->next->prev = result;
    		}

    	return result;
}

template <typename T>
typename List<T>::Node* List<T>::mergeSort(typename List<T>::Node* head) {
    	if (head == nullptr || head->next == nullptr)
        	return head;

    	typename List<T>::Node* first = head;
    	typename List<T>::Node* second = head->next;

    	while (second != nullptr && second->next != nullptr) {
        	first = first->next;
        	second = second->next->next;
    	}

    	typename List<T>::Node* middle = first->next;
    	middle->prev = nullptr;
    	first->next = nullptr;

    	typename List<T>::Node* left = mergeSort(head);
    	typename List<T>::Node* right = mergeSort(middle);

    	return merge(left, right);
}

template <typename T>
void List<T>::mergeSort() {
    	head = mergeSort(head);

    	if (head != nullptr) {
        	tail = head;
        	while (tail->next != nullptr)
            		tail = tail->next;
    	}
}

template <typename T>
void List<T>::serialize(const std::string& filename){
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
		sortedList.mergeSort();
		std::cout << "Deserialization from " << filename << " file" << std::endl;
	}
	else{
		std::cout << filename << " file doesn't opened." << std::endl;
	}
	return sortedList;
}
