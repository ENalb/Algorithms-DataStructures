#ifndef GTREE_H
#define GTREE_H

#include "vector.h"
#include <functional>

template <typename T>
class GTree{
public:
	GTree();
	void traverse(typename GTree<T>::GTreeNode* current);
	void insert(std::function<T(int)> f, int level, int order);
	void insertHelper(typename GTree<T>::GTreeNode* node, typename GTree<T>::GTreeNode* newNode, int level, int order);
	void remove(int level, int order);
	void removeHelper(typename GTree<T>::GTreeNode* node, int level, int order);
	T execute(int number);
	T executeHelper(typename GTree<T>::GTreeNode* node, int number);
	typename GTree<T>::GTreeNode* getRoot();
private:
	struct GTreeNode{
		std::function<T(int)> function;
		Vector<GTreeNode*> children;
		GTreeNode(std::function<T(int)> f) : function{f}, children{} {}
		GTreeNode() {}
	};
	GTreeNode* root;
};

#include "gtree.tpp"

#endif
