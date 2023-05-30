#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

template <typename K, typename V>
int HashTable<K, V>::hash(const std::string& k) const {
    int sum = 0;
    for (int i = 0; i < k.size(); ++i) {
        sum += static_cast<int>(k[i]);
    }
    return sum;
}

template <typename K, typename V>
HashTable<K, V>::HashTable(int size) : tableSize{size}, elemCount{0} {
    hashTable = std::vector<Pair<K, V>>(tableSize);
}

template <typename K, typename V>
void HashTable<K, V>::insert(const K& k, const V& v) {
    int index = hash(k);
    Pair<K, V>* current = &hashTable[index];
    if (current == nullptr) {
        current = new Pair<K, V>(k, v);
        elemCount++;
        return;
    }
    if (current->isEmpty()) {
        current->setKey(k);
        current->setValue(v);
        elemCount++;
    } else {
        while (current->getNext() != nullptr) {
            if (current->getKey() == k) {
                current->setValue(v);
                return;
            }
            current = current->getNext();
        }
        Pair<K, V>* newNode = new Pair<K, V>(k, v);
        current->setNext(newNode);
        elemCount++;
    }
}

template <typename K, typename V>
void HashTable<K,V>::remove(const K& k){
    int index = hash(k);
    int originalIndex = index;
    while (true) {
        if (hashTable[index].getKey() == k) {
            hashTable.erase(hashTable.begin() + index);
            elemCount--;
            return;
        }
        index = (index + 1) % tableSize;
        if (index == originalIndex) {
            throw std::out_of_range("Key not found in table");
        }
    }
}

template <typename K, typename V>
V HashTable<K, V>::find(const K& k) const {
    int index = hash(k);
    int originalIndex = index;
    while (true) {
        if (hashTable[index].getKey() == k) {
            return hashTable[index].getValue();
        }
        index = (index + 1) % tableSize;
        if (index == originalIndex) {
            throw std::out_of_range("Key not found in table");
        }
    }
}

template <typename K, typename V>
K HashTable<K, V>::find(const V& v) const{
	for (const auto& pair : hashTable) {
        if (!pair.isEmpty() && pair.getValue() == v) {
            return pair.getKey();
        }
    }
    throw std::out_of_range("Value not found in table");
}