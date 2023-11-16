#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "hash_node.h"

class HashTable {
    public:
        HashTable();

        ~HashTable();

        void setSize(unsigned int size, int pages);

        int primaryHashFunction(const unsigned int& pid);

        int secondaryHashFunction(const unsigned int& pid);

        void insert(const unsigned int& pid);

        int search(const unsigned int& pid);

        // void ordered_insert(const unsigned int& pid);

        // void open_insert(const unsigned int& pid);

        // int ordered_search(const unsigned int& pid);

        // int open_search(const unsigned int& pid);

        void write(const unsigned int& pid, unsigned int addr, int x);

        void read(unsigned int pid, unsigned int addr);

        void remove(const unsigned int& pid);
        
        void print(int m);

    private:
        std::vector<HashNode*> table;
        unsigned int hash_table_size;
        int m;
        int pages;
        HashNode* current;
        HashNode* prev;
};

#endif