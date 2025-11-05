/**
 * HashTable.h
 * Ian Bonifas
 * CS 3100
 * header file for HashTable
 * November 1
 *
 */
#ifndef HashTable_H
#define HashTable_H

#include <string>
#include <iostream>
#include <optional>
#include <vector>

//creates a hash bucket class
class HashTableBucket {
public:
    std::string code;
    std::string key;
    size_t value;

    HashTableBucket() : code("ESS") {
    }

    void setter(std::string key, int value);

    void empty();

    bool isEmpty();

    void print();
};

//sets key value and to NORMAL
inline void HashTableBucket::setter(std::string key, int value) {
    this->key = key;
    this->value = value;
    this->code = "NORMAL";
}

//set to empty after removal
inline void HashTableBucket::empty() {
    this->key = "";
    this->value = 0;
    this->code = "EAR";
}

//checks to see if is empty
inline bool HashTableBucket::isEmpty() {
    if (this->code == "EAR" || this->code == "ESS") {
        return true;
    }
    return false;
}

//prints bucket
inline void HashTableBucket::print() {
    std::cout << this->value << " " << this->key << " " << this->code << std::endl;
}

//class for HashTable
class HashTable {
public:
    size_t Capacity;
    double alpha;
    size_t size;
    int OffsetArray[7] = {2, 4, 7, 6, 5, 3, 1};
    std::vector<HashTableBucket> table;

    HashTable();

    HashTable(size_t initcapacity);

    bool insert(const std::string key, const size_t value);

    bool remove(const std::string key, const size_t value);

    bool contains(const std::string key, const size_t value);

    std::optional<size_t> get(const std::string key);

    std::size_t &operator[](const std::string key);

    std::vector<std::string> keys();

    double getalph();

    size_t getsize();

    size_t getcapacity();

    //overloads <<
    friend std::ostream &operator<<(std::ostream &os, HashTable &hashTable) {
        int offset = 0;
        while (offset < hashTable.size) {
            HashTableBucket *ref = &hashTable.table[offset];
            if (!ref->isEmpty()) {
                os << ref->key << " " << ref->value;
            }
            offset++;
            if (offset == hashTable.size) {
                return os;
            }
        }
    }
};


#endif
