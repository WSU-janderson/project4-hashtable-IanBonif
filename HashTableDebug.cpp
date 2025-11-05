/**
*Ian Bonifas
 *CS 3100
 *November 1
 *test file
 * HashTableDebug.cpp
 *
 * Write your tests in this file
 *
 */
#include <iostream>

#include "HashTable.h"

int main() {
    // std::cout << "Hello, World!" << std::endl;
    //test HashTableBucket
    //HashTableBucket b1;
    //b1.setter("John",1234);
    // b1.print();
    // std::cout <<b1.isEmpty()<<std::endl;;
    // b1.empty();
    // std::cout <<b1.isEmpty()<<std::endl;;
    //test build function
    HashTable t1;
    //test insert
    t1.insert("John", 1234);
    t1.insert("James", 123);
    // test os overload
    std::cout << t1 << std::endl;
    //test keys function
    std::vector<std::string> keys = t1.keys();
    //test alph
    std::cout << t1.getalph() << std::endl;
    //test remove function
    t1.remove("James", 123);
    //test the contains function
    std::cout << t1.contains("John", 1234) << std::endl;
    //test op[] overload
    t1["John"] = 2222;
    //test alph again
    std::cout << t1.getalph() << std::endl;
    //test the other build function
    HashTable t2(7);
    return 0;
}
