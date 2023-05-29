#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root{nullptr} {}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::getRoot() const{
	return root;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const T& rootItem) : root{new BinaryNode(rootItem)} {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree) : root{tree.root} {}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	clear();
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const{
	return root == nullptr;
}

template <typename T>
int BinarySearchTree<T>::getHeightHelper(const typename BinarySearchTree<T>::BinaryNode* root) const{
	if (!root) {
        return 0;
    }
    int leftHeight = getHeightHelper(root->left);
    int rightHeight = getHeightHelper(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

template <typename T>
int BinarySearchTree<T>::getHeight() const{
	return getHeightHelper(root);
}

template <typename T>
int BinarySearchTree<T>::getNumberOfNodesHelper(typename BinarySearchTree<T>::BinaryNode* root) const{
	if(!root){
		return 0;
	}
	return (1 + getNumberOfNodesHelper(root->left) + getNumberOfNodesHelper(root->right));
}

template <typename T>
int BinarySearchTree<T>::getNumberOfNodes() const{
	return getNumberOfNodesHelper(root);
}

template <typename T>
T BinarySearchTree<T>::getRootData() const{
	return root->value;
}

template <typename T>
void BinarySearchTree<T>::setRootData(const T& data){
	if(!root){
		return;
	}
	root->value = data;
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::insertInorder(typename BinarySearchTree<T>::BinaryNode* subTreePtr, typename BinarySearchTree<T>::BinaryNode* newNode){
	BinaryNode* tempPtr;
	if(!subTreePtr){
		return newNode;
	}
	else if(subTreePtr->value > newNode->value){
		tempPtr = insertInorder(subTreePtr->left, newNode);
		subTreePtr->left = tempPtr;
	}
	else{
		tempPtr = insertInorder(subTreePtr->right, newNode);
		subTreePtr->right = tempPtr;
	}
	return subTreePtr;
}

template <typename T>
void BinarySearchTree<T>::add(const T& newEntry){
	typename BinarySearchTree<T>::BinaryNode* newNode = new BinaryNode(newEntry);
	newNode->left = nullptr;
    newNode->right = nullptr;
	root = insertInorder(root, newNode);
}

template <typename T>
void BinarySearchTree<T>::insertInorderIterative(const T& value) {
    typename BinarySearchTree<T>::BinaryNode* newNode = new BinaryNode(value);
    if (!root) {
        root = newNode;
        return;
    }
    BinaryNode* current = root;
    BinaryNode* prev = nullptr;
    while (current) {
        prev = current;
        if (value <= current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (value <= prev->value) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

template <typename T>
void BinarySearchTree<T>::addIterative(const T& value) {
    insertInorderIterative(value);
}

template <typename T>
T BinarySearchTree<T>::getEntry(const T& anEntry) const{
	typename BinarySearchTree<T>::BinaryNode* ptr = findNode(root, anEntry);
	if(!ptr){
		std::cout << "Entry doesn't exist" << std::endl;
	}
	return ptr->value;
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::findNode(typename BinarySearchTree<T>::BinaryNode* treePtr, const T& target) const{
	if (treePtr == nullptr) {
        return nullptr;
    }
    if (treePtr->value == target) {
        return treePtr;
    } 
    else if (treePtr->value > target) {
        return findNode(treePtr->left, target);
    } 
    return findNode(treePtr->right, target);
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::findNodeIterative(typename BinarySearchTree<T>::BinaryNode* treePtr, const T& target) const{
	if(isEmpty()){
		return nullptr;
	}
	typename BinarySearchTree<T>::BinaryNode* ptr = treePtr;
	while(ptr){
		if(ptr->value == target){
			return ptr;
		}
		else if(ptr->value > target){
			ptr = ptr->left;
		}
		else{
			ptr = ptr->right;
		}
	}
	return nullptr;
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& anEntry) const{
	return findNode(root, anEntry) != nullptr;
}

template <typename T>
bool BinarySearchTree<T>::containsIterative(const T& anEntry) const{
	return findNodeIterative(root, anEntry) != nullptr;
}

template <typename T>
T BinarySearchTree<T>::getMin() const{
	if(isEmpty()){
		std::cout << "Tree is empty" << std::endl;
	}
	typename BinarySearchTree<T>::BinaryNode* cur = root;
	while(cur->left){
		cur = cur->left;
	}
	return cur->value;
}

template <typename T>
T BinarySearchTree<T>::getMax() const{
	if(isEmpty()){
		std::cout << "Tree is empty" << std::endl;
	}
	typename BinarySearchTree<T>::BinaryNode* cur = root;
	while(cur->right){
		cur = cur->right;
	}
	return cur->value;
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::findMinNode(typename BinarySearchTree<T>::BinaryNode* treePtr) const{
	if(!treePtr){
		return nullptr;
	}
	while(treePtr->left){
		treePtr = treePtr->left;
	}
	return treePtr;
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::findMaxNode(typename BinarySearchTree<T>::BinaryNode* treePtr) const{
	if(!treePtr){
		return nullptr;
	}
	while(treePtr->right){
		treePtr = treePtr->right;
	}
	return treePtr;
}

template <typename T>
void BinarySearchTree<T>::inorder(void visit(T&), typename BinarySearchTree<T>::BinaryNode* treePtr) const{
	if(!treePtr){
		return;
	}
	inorder(visit, treePtr->left);
	T item = treePtr->value;
	visit(item);
	inorder(visit, treePtr->right);
}

template <typename T>
void BinarySearchTree<T>::inorderTraverse(void visit(T&)) const{
	inorder(visit, root);
}

template <typename T>
void BinarySearchTree<T>::preorder(void visit(T&), typename BinarySearchTree<T>::BinaryNode* treePtr) const{
	if(!treePtr){
		return;
	}
	T item = treePtr->value;
	visit(item);
	preorder(visit, treePtr->left);
	preorder(visit, treePtr->right);
}

template <typename T>
void BinarySearchTree<T>::preorderTraverse(void visit(T&)) const{
	preorder(visit, root);
}

template <typename T>
void BinarySearchTree<T>::postorder(void visit(T&), typename BinarySearchTree<T>::BinaryNode* treePtr) const{
	if(!treePtr){
		return;
	}
	postorder(visit, treePtr->left);
	postorder(visit, treePtr->right);
	T item = treePtr->value;
	visit(item);
}

template <typename T>
void BinarySearchTree<T>::postorderTraverse(void visit(T&)) const{
	postorder(visit, root);
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::findSuccessorNode(typename BinarySearchTree<T>::BinaryNode* treePtr, const T& target) const{
	typename BinarySearchTree<T>::BinaryNode* found = findNode(treePtr, target);
	if(!found){
		return nullptr;
	}
	if(found->right){
		return findMinNode(found->right);
	}
	else{
		typename BinarySearchTree<T>::BinaryNode* successor = nullptr;
		typename BinarySearchTree<T>::BinaryNode* current = treePtr;
		while(current != found){
			if (found->value < current->value) {
                successor = current;
                current = current->left;
            } else {
                current = current->right;
            }
		}
		return successor;
	}
	return nullptr;
}

template <typename T>
T BinarySearchTree<T>::getSuccessor(const T& anEntry) const{
	typename BinarySearchTree<T>::BinaryNode* found = findSuccessorNode(root, anEntry);
	if(!found){
		std::cout << "Successor isn't found" << std::endl;
	}
	return found->value;
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::findPredecessorNode(typename BinarySearchTree<T>::BinaryNode* treePtr, const T& target) const{
	typename BinarySearchTree<T>::BinaryNode* found = findNode(treePtr, target);
	if(!found){
		return nullptr;
	}
	if(found->left){
		typename BinarySearchTree<T>::BinaryNode* predecessor = found->left;
        while (predecessor->right) {
            predecessor = predecessor->right;
        }
        return predecessor;
	}
	typename BinarySearchTree<T>::BinaryNode* predecessor = nullptr;
    typename BinarySearchTree<T>::BinaryNode* current = treePtr;
    while (current != found) {
        if (found->value > current->value) {
            predecessor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return predecessor;
}

template <typename T>
T BinarySearchTree<T>::getPredecessor(const T& anEntry) const{
	BinaryNode* predecessorNode = findPredecessorNode(root, anEntry);
    if (!predecessorNode) {
    	std::cout << "Predecessor not found" << std::endl;
    }
    return predecessorNode->value;
}

template <typename T>
void BinarySearchTree<T>::removeSuccessor(typename BinarySearchTree<T>::BinaryNode* node) {
    BinaryNode* parent = node;
    BinaryNode* successor = node->right;
    while (successor->left) {
        parent = successor;
        successor = successor->left;
    }
    node->value = successor->value;
    if (parent == node)
        parent->right = successor->right;
    else
        parent->left = successor->right;
    delete successor;
}

template <typename T>
bool BinarySearchTree<T>::removeIterative(const T& target) {
    BinaryNode* parent = nullptr;
    BinaryNode* current = root;
    while (current && current->value != target) {
        parent = current;
        if (target < current->value)
            current = current->left;
        else
            current = current->right;
    }
    if (!current)
        return false;
    if (!current->left && !current->right) {
        if (current == root)
            root = nullptr;
        else if (current == parent->left)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete current;
    }
    else if (!current->left || !current->right) {
        BinaryNode* child = current->left ? current->left : current->right;
        if (current == root)
            root = child;
        else if (current == parent->left)
            parent->left = child;
        else
            parent->right = child;
        delete current;
    }
    else {
        BinaryNode* successor = findMinNode(current->right);
        current->value = successor->value;
        removeSuccessor(successor);
    }
    return true;
}

template <typename T> 
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::removeLeftmostNode(typename BinarySearchTree<T>::BinaryNode* subTreePtr, T& inorderSuccessor){
	if(!subTreePtr->left){
		inorderSuccessor = subTreePtr->value;
		return removeNode(subTreePtr);
	}
	return removeLeftmostNode(subTreePtr->left, inorderSuccessor);
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::removeNode(typename BinarySearchTree<T>::BinaryNode* node){
	if (!node->left && !node->right) {
        delete node;
        return nullptr;
    }
    else if (!node->left) {
        typename BinarySearchTree<T>::BinaryNode* temp = node->right;
        delete node;
        return temp;
    }
    else if (!node->right) {
        typename BinarySearchTree<T>::BinaryNode* temp = node->left;
        delete node;
        return temp;
    }
    else {
        int inorderSuccessor;
        typename BinarySearchTree<T>::BinaryNode* tempPtr = removeLeftmostNode(node->right, inorderSuccessor);
        node->right = tempPtr;
        node->value = inorderSuccessor;
        return node;
    }
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::removeValue(typename BinarySearchTree<T>::BinaryNode* subTree, const T target, bool& success){
	if (!subTree) {
        success = false;
        return nullptr;
    }
    if (subTree->value == target) {
        success = true;
        return removeNode(subTree);
    }
    if (subTree->value > target) {
        subTree->left = removeValue(subTree->left, target, success);
    }
    else {
        subTree->right = removeValue(subTree->right, target, success);
    }
    return subTree;
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::remove(const T& anEntry){
	bool success = false;
    typename BinarySearchTree<T>::BinaryNode* newRoot = removeValue(root, anEntry, success);
    return newRoot;
}

template <typename T>
void BinarySearchTree<T>::clearHelper(typename BinarySearchTree<T>::BinaryNode* node){
	if(node){
		clearHelper(node->left);
		clearHelper(node->right);
		delete node;
	}
}

template <typename T>
void BinarySearchTree<T>::clear(){
	clearHelper(root);
	root = nullptr;
}

template <typename T>
void BinarySearchTree<T>::printInorderHelper(typename BinarySearchTree<T>::BinaryNode* node) const {
    if (node) {
        printInorderHelper(node->left);
        std::cout << node->value << " ";
        printInorderHelper(node->right);
    }
}

template <typename T>
void BinarySearchTree<T>::printInorder() const {
    printInorderHelper(root);
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::printPreorder() const {
    printPreorder(root);
}

template <typename T>
void BinarySearchTree<T>::printPreorder(typename BinarySearchTree<T>::BinaryNode* node) const {
    if (node) {
        std::cout << node->value << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

template <typename T>
void BinarySearchTree<T>::printPostorder() const {
    printPostorder(root);
}

template <typename T>
void BinarySearchTree<T>::printPostorder(typename BinarySearchTree<T>::BinaryNode* node) const {
    if (node) {
        printPostorder(node->left);
        printPostorder(node->right);
        std::cout << node->value << " ";
    }
}

template <typename T>
void BinarySearchTree<T>::serializeHelper(typename BinarySearchTree<T>::BinaryNode* node, std::ofstream& file) {
	if(node == nullptr){
		return;
	}
	file << node->value << " ";
	serializeHelper(node->left, file);
	serializeHelper(node->right, file);
}

template <typename T>
void BinarySearchTree<T>::serialize(const std::string& filename) {
	std::ofstream file(filename);
	if(!file.is_open()){
		std::cout << "Can't open file." << std::endl;
		return;
	}
	serializeHelper(root, file);
	file.close();
}

template <typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::deserializeHelper(std::ifstream& file) {
    T value;
    if (file >> value) {
        BinaryNode* newNode = new BinaryNode(value);
        newNode->left = deserializeHelper(file);
        newNode->right = deserializeHelper(file);
        return newNode;
    }
    return nullptr;
}

template <typename T>
void BinarySearchTree<T>::deserialize(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Can't open file." << std::endl;
        return;
    }

    clear(); 

    root = deserializeHelper(file); 

    file.close();
}
