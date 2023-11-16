#ifndef HASH_NODE_H
#define HASH_NODE_H

#include <iostream>
#include <vector>
#include <cmath>

class HashNode {
    public:
        int key;
        int value;
        HashNode* next;
        int * array_ptr;

        HashNode(const int& k, const int& len);

};

#endif