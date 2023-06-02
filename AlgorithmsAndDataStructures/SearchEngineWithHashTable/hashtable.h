#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include "pair.h"
#include <string>
#include "d_list.h"

template <typename K, typename V>
class HashTable{
public:
	HashTable(int size);
	void insert(const K& k, const V& v);
	void remove(const K& k);
	const V& find(const K& k) const;
	K find(const V& v) const;
	std::vector<K> getKeys() const;
	int size() const;
	const std::vector<Pair<K, V>>& getHashTable() const;
	Pair<K, V>& operator[](const K& k);
private:
	std::vector<Pair<K, V>> hashTable;
	int tableSize;
	int elemCount;
	int hash(const std::string& k) const;
};

#include "hashtable.tpp"

#endif