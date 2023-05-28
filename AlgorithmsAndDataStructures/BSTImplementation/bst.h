#ifndef BST_H
#define BST_H

template <typename T>
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(const T& rootItem);
	BinarySearchTree(const BinarySearchTree<T>& tree);
	~BinarySearchTree();
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	T getRootData() const;
	void setRootData(const T& data);
	void add(const T& newEntry);
	void addIterative(const T& value);
	T getMin() const;
	T getMax() const;
	T getEntry(const T& anEntry) const;
	bool contains(const T& anEntry) const;
	bool containsIterative(const T& anEntry) const;
	void preorderTraverse(void visit(T&)) const;
	void inorderTraverse(void visit(T&)) const;
	void postorderTraverse(void visit(T&)) const;
	typename BinarySearchTree<T>::BinaryNode* remove(const T& anEntry);
	void clear();
	T getSuccessor(const T& anEntry) const;
    T getPredecessor(const T& anEntry) const;
    void printInorder() const;
    void printPreorder() const;
    void printPostorder() const;
protected:
	int getHeightHelper(const typename BinarySearchTree<T>::BinaryNode* root) const;
	int getNumberOfNodesHelper(typename BinarySearchTree<T>::BinaryNode* root) const;
	typename BinarySearchTree<T>::BinaryNode* findNode(typename BinarySearchTree<T>::BinaryNode* treePtr, const T& target) const;
	typename BinarySearchTree<T>::BinaryNode* findNodeIterative(typename BinarySearchTree<T>::BinaryNode* treePtr, const T& target) const;
	typename BinarySearchTree<T>::BinaryNode* findMinNode(typename BinarySearchTree<T>::BinaryNode* treePtr) const;
    typename BinarySearchTree<T>::BinaryNode* findMaxNode(typename BinarySearchTree<T>::BinaryNode* treePtr) const;
	typename BinarySearchTree<T>::BinaryNode* insertInorder(typename BinarySearchTree<T>::BinaryNode* subTreePtr, typename BinarySearchTree<T>::BinaryNode* newNode);
	void insertInorderIterative(const T& value);
	void inorder(void visit(T&), typename BinarySearchTree<T>::BinaryNode* treePtr) const;
	void preorder(void visit(T&), typename BinarySearchTree<T>::BinaryNode* treePtr) const;
	void postorder(void visit(T&), typename BinarySearchTree<T>::BinaryNode* treePtr) const;
	typename BinarySearchTree<T>::BinaryNode* removeValue(typename BinarySearchTree<T>::BinaryNode* subTreePtr, const T target, bool& success);
	typename BinarySearchTree<T>::BinaryNode* removeNode(typename BinarySearchTree<T>::BinaryNode* nodePtr); 
	typename BinarySearchTree<T>::BinaryNode* removeLeftmostNode(typename BinarySearchTree<T>::BinaryNode* subTreePtr, T& inorderSuccessor); 
	void clearHelper(typename BinarySearchTree<T>::BinaryNode* node);
    typename BinarySearchTree<T>::BinaryNode* findSuccessorNode(typename BinarySearchTree<T>::BinaryNode* treePtr, const T& target) const;
    typename BinarySearchTree<T>::BinaryNode* findPredecessorNode(typename BinarySearchTree<T>::BinaryNode* treePtr, const T& target) const;
    void printInorderHelper(typename BinarySearchTree<T>::BinaryNode* treePtr) const;
    void printPreorder(typename BinarySearchTree<T>::BinaryNode* node) const;
    void printPostorder(typename BinarySearchTree<T>::BinaryNode* node) const;
private:
	struct BinaryNode{
		T value;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode() : value{0}, left{nullptr}, right{nullptr} {}
		BinaryNode(T x) : value{x}, left{nullptr}, right{nullptr} {}
		BinaryNode(T x, BinaryNode* l, BinaryNode* r) : value{x}, left{l}, right{r} {}
	};
	BinaryNode* root;
};

#include "bst.tpp"

#endif