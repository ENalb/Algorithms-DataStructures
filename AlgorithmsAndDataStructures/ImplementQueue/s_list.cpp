#include "s_list.h"

List::~List(){
	while(head){
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void List::push_front(int val){
	Node* new_node = new Node(val);
	new_node->next = head;
	head = new_node;
	if(!tail){
		tail = head;
	}
}

void List::push_back(int val){
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

void List::pop_front(){
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

void List::pop_back(){
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

bool List::empty(){
	if(head == nullptr){
		return true;
	}
	return false;
}

int& List::front(){
	return head->val;
}

int& List::back(){
	return tail->val;
}

void List::remove(int value){
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

int List::size() const{
	int count = 0;
	Node* current = head;
	while(current != nullptr){
		count++;
		current = current->next;
	}
	return count;
}