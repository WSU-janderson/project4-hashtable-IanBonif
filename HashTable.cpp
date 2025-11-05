/**
 * HashTable.cpp
 * Ian Bonifas
 * CS 3100
 * November 1
 * Class for HashTable
 *
 */
#include "HashTable.h"

#include <vector>
#include <exception>
#include <functional>
//builds hashtable
HashTable::HashTable() : Capacity(0), alpha(0), size(0) {
    //sets size to 8
    this->size = 8;
    //sets alpha to 0
    this->alpha = 0.0;
    //sets capacity to 0
    this->Capacity = 0;
    //builds vector
    std::vector<HashTableBucket> table;
    //resizes vector
    table.resize(this->size);
    //sets table to this->table
    this->table = table;
}


//builds hash table with size
HashTable::HashTable(size_t initCapacity) {
    //sets size to input
    this->size = initCapacity;
    //sets alpha to 0
    this->alpha = 0.0;
    //sets capacity to 0
    this->Capacity = 0;
    //builds vector
    std::vector<HashTableBucket> table;
    //resizes vector to input
    table.resize(this->size);
    //sets table to this->table
    this->table = table;
}

bool HashTable::insert(const std::string key, const size_t value) {
    //sets offset to 0
    int offset = 0;
    //makes hasher for strings
    std::hash<std::string> hasher;
    //uses hasher
    std::size_t hash_value = hasher(key);
    //loops when offset less than size
    while (offset <= this->size) {
        //build first prob
        int prob = this->OffsetArray[offset];
        //makes home
        int home = size_t(hash_value) % this->size;
        //makes second part of prob
        int fullProb = home + prob % this->size;
        //gets pointer to get through table
        HashTableBucket *ref = &this->table[fullProb];
        //checks for empty
        if (ref->isEmpty()) {
            //sets value and key
            ref->setter(key, value);
            //add to Capacity
            this->Capacity++;
            //return true
            return true;
        }
        //returns false if dup
        if (ref->value == value) {
            return false;
        }
        //add to offset
        offset++;
    }
}

bool HashTable::remove(const std::string key, const size_t value) {
    //sets up offset
    int offset = 0;
    //makes hasher
    std::hash<std::string> hasher;
    //makes hashed value
    std::size_t hash_value = hasher(key);
    //loops through probs
    while (offset <= this->size) {
        //first part of prob
        int prob = this->OffsetArray[offset];
        //makes home
        int home = size_t(hash_value) % this->size;
        //finishes probs
        int fullProb = home + prob % this->size;
        //gets pointer to go through table
        HashTableBucket *ref = &this->table[fullProb];
        //test if key == key
        if (ref->key == key) {
            //if equals clears bucket
            ref->empty();
            //takes 1 from Capacity
            this->Capacity--;
            //returns true
            return true;
        }
        //adds to offset
        offset++;
    }
    //returns false if not in vector
    return false;
}

bool HashTable::contains(const std::string key, const size_t value) {
    //sets up
    int offset = 0;
    //build hash function
    std::hash<std::string> hasher;
    //gets hashed value
    std::size_t hash_value = hasher(key);
    //goes through table
    while (offset <= this->size) {
        //first part of prob
        int prob = this->OffsetArray[offset];
        //makes home
        int home = size_t(hash_value) % this->size;
        //finished prob
        int fullProb = home + prob % this->size;
        //ref to bucket at index
        HashTableBucket *ref = &this->table[fullProb];
        //if in return true
        if (ref->key == key) {
            //return true
            return true;
        }
        //adds to offset
        offset++;
    }
    return false;
}

std::optional<size_t> HashTable::get(const std::string key) {
    int offset = 0;
    std::hash<std::string> hasher;
    std::size_t hash_value = hasher(key);
    while (offset <= this->size) {
        int prob = this->OffsetArray[offset];
        int home = size_t(hash_value) % this->size;
        int fullProb = home + prob % this->size;
        HashTableBucket *ref = &this->table[fullProb];
        if (ref->key == key) {
            return ref->value;
        }
        offset++;
    }
    return std::nullopt;
}

std::size_t &HashTable::operator[](const std::string key) {
    //sets up offset
    int offset = 0;
    //builds hasher
    std::hash<std::string> hasher;
    //gets hashed value
    std::size_t hash_value = hasher(key);
    //walks through table
    while (offset <= this->size) {
        //first part of prob
        int prob = this->OffsetArray[offset];
        //gets home
        int home = size_t(hash_value) % this->size;
        //second part of prob
        int fullProb = home + prob % this->size;
        //gets pointer to get through table
        HashTableBucket *ref = &this->table[fullProb];
        //if keys match return value
        if (ref->key == key) {
            //returns value
            return ref->value;
        }
        //adds to offset
        offset++;
    }
    //throws out of bounds exception
    throw std::exception();
}

std::vector<std::string> HashTable::keys() {
    //build vector of keys
    std::vector<std::string> keys;
    //resizes vector
    keys.resize(this->size);
    //loops to get through table
    for (int i = 0; i < this->size; i++) {
        //gets ref at index
        HashTableBucket *ref = &this->table[i];
        //checks for not empty
        if (!ref->isEmpty()) {
            //adds keys to vector
            keys.insert(keys.begin() + i, ref->key);
        }
    }
    //returns keys vector
    return keys;
}

double HashTable::getalph() {
    //does the alpha math
    this->alpha = double(this->Capacity) / double(this->size);
    //returns alpha
    return this->alpha;
}

size_t HashTable::getsize() {
    //returns size
    return this->size;
}

size_t HashTable::getcapacity() {
    //returns capacity
    return this->Capacity;
}
