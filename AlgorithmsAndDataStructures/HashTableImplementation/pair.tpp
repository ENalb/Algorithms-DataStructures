#include "pair.h"

template <typename K, typename V>
Pair<K,V>::Pair(const K& k, const V& v) 
	: key{k}, value{v}, next{nullptr} {}

template <typename K, typename V>
void Pair<K,V>::setKey(const K& k){
	key = k;
}

template <typename K, typename V>
void Pair<K,V>::setValue(const V& v){
	value = v;
}

template <typename K, typename V>
void Pair<K,V>::setNext(Pair<K, V>* n){
	next = n;
}

template <typename K, typename V>
Pair<K, V>* Pair<K,V>::getNext() const{
	return next;
}

template <typename K, typename V>
K Pair<K,V>::getKey() const{
	return key;
}

template <typename K, typename V>
V Pair<K,V>::getValue() const{
	return value;
}

template <typename K, typename V>
bool Pair<K,V>::isEmpty() const{
	if (key == K() && value == V()){
		return true;
	}
	return false;
}