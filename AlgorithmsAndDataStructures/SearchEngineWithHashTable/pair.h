#ifndef PAIR_H
#define PAIR_H

template <typename K, typename V>
class Pair{
public:
	Pair() = default;
	Pair(const K& k, const V& v);
	void setKey(const K& k);
	void setValue(const V& v);
	void setNext(Pair<K, V>* n);
	K getKey() const;
	const V& getValue() const;
	V& getValue();
	Pair<K, V>* getNext() const;
	bool isEmpty() const;
private:
	K key;
	V value;
	Pair<K, V>* next;
};

#include "pair.tpp"

#endif