#include "gtree.h"
#include <iostream>

template <typename T>
GTree<T>::GTree() : root{nullptr} {}

template <typename T>
typename GTree<T>::GTreeNode* GTree<T>::getRoot() {
    return root;
}

template <typename T>
void GTree<T>::traverse(typename GTree<T>::GTreeNode* current) {
    if (!current) {
        return;
    }
    for (size_t i = 0; i < current->children.size(); ++i) {
        traverse(current->children[i]);
    }
}

template <typename T>
void GTree<T>::insert(std::function<T(int)> f, int level, int order) {
    if (level < 0) {
        std::cout << "Invalid level value" << std::endl;
        return;
    }
    GTreeNode* newNode = new GTreeNode(f);
    if (level == 0) {
        if (order < 0 || order > 0) {
            std::cout << "Invalid order value" << std::endl;
            delete newNode;
            return;
        }
        if (!root) {
            root = newNode;
        } 
        else {
            std::cout << "Root already exists" << std::endl;
            delete newNode; 
        }
    } 
    else {
        insertHelper(root, newNode, level - 1, order);
    }
}

template <typename T>
void GTree<T>::insertHelper(GTreeNode* node, GTreeNode* newNode, int level, int order) {
    if (level == 0) {
        if (order < 0 || order > node->children.size()) {
            std::cout << "Invalid order value" << std::endl;
            delete newNode; 
            return;
        }

        node->children.insert(order, newNode);
    } else {
        if (node->children.empty()) {
            std::cout << "Invalid level value" << std::endl;
            delete newNode; 
            return;
        }

        insertHelper(node->children[order], newNode, level - 1, order);
    }
}

template <typename T>
void GTree<T>::remove(int level, int order){
	if(root == nullptr){
		std::cout << "Tree empty" << std::endl;
		return;
	}
	else{
		if(level >= 0 && level < root->children.size()){
			if(order >= 0 && order < root->children[level].children.size()){
				root->children[level]->children.erase(order);
			}
			else{
				std::cout << "Invalid order value" << std::endl;
			}
		}
		else{
			std::cout << "Invalid level value" << std::endl;
		}
	}
}

template <typename T>
T GTree<T>::execute(int number){
	if(!root){
		std::cout << "Tree is empty" << std::endl;
		return T();
	}
	return executeHelper(root, number);
}

template <typename T>
T GTree<T>::executeHelper(typename GTree<T>::GTreeNode* node, int number) {
    if (node == nullptr) {
        return T();
    }
    T result = node->function(number);
    for (size_t i = 0; i < node->children.size(); ++i) {
        T childResult = executeHelper(node->children[i], result); 
        result = childResult; 
    }
    return result;
}
