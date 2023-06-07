#include "avl_tree.h"
#include <iostream>

template <typename T>
AVL<T>::AVL() 
	: root{nullptr},
		right{nullptr}, 
		left{nullptr}, 
		value{}, 
		height{0} 
{
}

template <typename T>
AVL<T>::AVL(T val) 
	: root{nullptr},
		right{nullptr}, 
		left{nullptr}, 
		value{val}, 
		height{1} 
{
}

template <typename T>
AVL<T>::AVL(AVL* ro, AVL* r, AVL* l, T v, int h) 
	: root{ro},
		right{r}, 
		left{l}, 
		value{v}, 
		height{h} 
{
}

template <typename T>
AVL<T>* AVL<T>::getRoot() const{
	return root;
}

template <typename T>
int AVL<T>::getHeight(AVL* node) const{
	if(!node){
		return 0;
	}
	updateHeight(node);
	return node->height;
}

template <typename T>
int AVL<T>::getHeight() const{
	return getHeight(root);
}


template <typename T>
void AVL<T>::updateHeight(AVL* node) const{
	node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

template <typename T>
int AVL<T>::getBalanceFactor(AVL* node) const{
	if(!node){
		return 0;
	}
	return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
AVL<T>* AVL<T>::leftRotation(AVL* node){
	AVL* tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	updateHeight(node);
	updateHeight(tmp);
	return tmp;
}

template <typename T>
AVL<T>* AVL<T>::rightRotation(AVL* node){
	AVL* tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	updateHeight(node);
	updateHeight(tmp);
	return tmp;
}

template <typename T>
void AVL<T>::inorderTraversal(AVL* node) const{
	if(!node){
		return;
	}
	if(node){
		inorderTraversal(node->left);
		std::cout << node->value << " ";
		inorderTraversal(node->right);
	}
}

template <typename T>
void AVL<T>::inorderTraversal() const{
	inorderTraversal(root);
}

template <typename T>
void AVL<T>::preorderTraversal(AVL* root) const{
	if(root){
		std::cout << root->value << " ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

template <typename T>
void AVL<T>::preorderTraversal() const{
	preorderTraversal(root);
}

template <typename T>
void AVL<T>::postOrderTraversal(AVL* root) const{
	if(root){
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		std::cout << root->value << " ";
	}
}

template <typename T>
void AVL<T>::postOrderTraversal() const{
	postOrderTraversal(root);
}

template <typename T>
AVL<T>* AVL<T>::insert(AVL* root, T key){
	if(!root){
		return new AVL(key);
	}
	if(key > root->value){
		root->right = insert(root->right, key);
	}
	else if(key < root->value){
		root->left = insert(root->left, key);
	}
	else{
		return root;
	}
	updateHeight(root);
	int balanceFactor = getBalanceFactor(root);
	if(balanceFactor > 1 && key < root->left->value){
		return rightRotation(root);
	}
	else if(balanceFactor < -1 && key > root->right->value){
		return leftRotation(root);
	}
	if(balanceFactor > 1 && key > root->left->value){
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	if(balanceFactor < -1 && key < root->right->value){
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}
	return root;
}

template <typename T>
void AVL<T>::insert(T key){
	root = insert(root, key);
}

template <typename T>
AVL<T>* AVL<T>::remove(AVL* root, T key){
	if(!root){
		return root;
	}
	if(key < root->value){
		root->left = remove(root->left, key);
	}
	else if(key > root->value){
		root->right = remove(root->right, key);
	}
	else{
		if(!root->left && !root->right){
			delete root;
			root = nullptr;
		}
		else if(!root->left){
			AVL* tmp = root;
			root = root->right;
			delete tmp;
		}
		else if(!root->right){
			AVL* tmp = root;
			root = root->left;
			delete tmp;
		}
		else{
			AVL* tmp = findMin(root->right);
			root->value = tmp->value;
			root->right = remove(root->right, tmp->value);
		}
	}
	updateHeight(root);
	int balanceFactor = getBalanceFactor(root);
	if(balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
		return rightRotation(root);
	}
	else if(balanceFactor < -1 && getBalanceFactor(root->right) <= 0){
		return leftRotation(root);
	}
	else if(balanceFactor > 1 && getBalanceFactor(root->left) < 0){
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	else if(balanceFactor < -1 && getBalanceFactor(root->right) > 0){
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}
	return root;
}

template <typename T>
AVL<T>* AVL<T>::findMin(AVL* node){
	if(!node){
		return nullptr;
	}
	while(node->left){
		node = node->left;
	}
	return node;
}

template <typename T>
void AVL<T>::remove(T key){
	remove(root, key);
}


template <typename T>
bool AVL<T>::find(AVL* root, T key){
	if(!root){
		return false;
	}
	if(key == root->value){
		return true;
	}
	else if(key < root->value){
		return find(root->left, key);
	}
	else{
		return find(root->right, key);
	}
	return false;
}

template <typename T>
bool AVL<T>::find(T key){
	return find(root, key);
}
