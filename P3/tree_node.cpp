#include <iostream>
#include <vector>
#include "tree_node.h"

TreeNode::TreeNode(char val) {
    value = val;
    isLeaf = false;
    isWord = false;
    children.resize(26, nullptr);
}
    