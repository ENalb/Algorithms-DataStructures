#ifndef AVL_TREE_H
#define AVL_TREE_H

template <typename T>
class AVL{
public:
	AVL();
	AVL(T val);
	AVL(AVL* ro, AVL* r, AVL* l, T v, int h);
	AVL* getRoot() const;
	int getHeight(AVL* node) const;
	int getHeight() const;
	void updateHeight(AVL* node) const;
	int getBalanceFactor(AVL* node) const;
	AVL* insert(AVL* root, T key);
	void insert(T key);
	AVL* remove(AVL* root, T key);
	void remove(T key);
	bool find(AVL* root, T key);
	bool find(T key);
	AVL* findMin(AVL* node);
	AVL* leftRotation(AVL* node);
	AVL* rightRotation(AVL* node);
	void inorderTraversal(AVL* node) const;
	void inorderTraversal() const;
	void preorderTraversal(AVL* root) const;
	void preorderTraversal() const;
	void postOrderTraversal(AVL* root) const;
	void postOrderTraversal() const;
private:
	AVL* root;
	AVL* right;
	AVL* left;
	T value;
	int height;
};

#include "avl_tree.tpp"

#endif