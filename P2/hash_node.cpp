#include <iostream>
#include <vector>
#include <cmath>
#include "hash_node.h"

HashNode::HashNode(const int& k, const int &len) 
{
  key = k;
  value = 0;
  next = nullptr;
  array_ptr = new int[len];
}

