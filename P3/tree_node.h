#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <vector>

class TreeNode {
    public:
        char value;
        bool isLeaf;
        bool isWord;
        std::vector<TreeNode*> children;

        TreeNode(char val);

    private:
        
};

#endif