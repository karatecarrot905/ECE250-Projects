#ifndef TRIE
#define TRIE

#include <iostream>
#include <vector>
#include "tree_node.h"

class Trie {
    public:
        TreeNode* root;

        Trie();

        void insert(std::string word);

        void insertCorpus(std::string word);

        int prefix(std::string pref);

        void erase(std::string word);

        void print(TreeNode* node, std::string output);

        void spellcheck(std::string word);

        std::string empty();

        void clear(TreeNode*& node);

        int getSize();

    private:

        TreeNode* current;
        bool isLeaf(TreeNode* node);
        int prefCounter(TreeNode* node);
        int size;
};

#endif