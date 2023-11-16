#include <iostream>
#include <vector>
#include "tree_node.h"
#include "trie.h"

    
Trie::Trie() {
    root = new TreeNode('*');
    current = nullptr;
    size = 0;
}

bool Trie::isLeaf(TreeNode* node) {
    for (TreeNode* child : node->children) {
        if (child != nullptr && child->value != '*') {
            return false;
        }
    }
    return true;
}

void Trie::insert(std::string word) {
    current = root;
    for (char c : word) {
        int index = c - 'A';

        if (current->children[index] == nullptr) {
            current->children[index] = new TreeNode(c);
        } else {
            if(current->isWord) {
                current->isLeaf = false;
            }
        }
        current = current->children[index];
    }

    if (current->isLeaf || current->isWord) {
        // checks if the word already exists
        std::cout << "failure" << std::endl;
        return;
    }
    current->isWord = true;
    current->isLeaf = isLeaf(current);
    size++;
    std::cout << "success" << std::endl;
}

void Trie::insertCorpus(std::string word) {
    current = root;
    for (char c : word) {
        int index = c - 'A';

        if (current->children[index] == nullptr) {
            current->children[index] = new TreeNode(c);
        } else {
            if(current->isWord) {
                current->isLeaf = false;
            }
        }
        current = current->children[index];
    }

    if (current->isLeaf || current->isWord) {
        //word already exists
        return;
    }
    current->isWord = true;
    current->isLeaf = isLeaf(current);
    size++;
}

int Trie::prefix(std::string pref) {
    current = root;

    for (char c : pref) {
        int index = c - 'A';
        if (current->children[index] == nullptr) {
            return 0;
        }
        current = current->children[index];
    }

    return prefCounter(current);
}

int Trie::prefCounter(TreeNode* node) {
    int NUM = 0;
    if (node == nullptr) {
        return 0;
    } 

    if (node->isWord) {
        NUM++;
    }

    for (int i = 0; i < node->children.size(); i++) {
        NUM += prefCounter(node->children[i]);
    }
    return NUM;
}


void Trie::erase(std::string word) {
    current = root;
    std::vector<TreeNode*> prevNodes;
    int len = word.length() - 1;

    for (char c : word) {
        int index = c - 'A';
        if (current->children[index] == nullptr) {
            std::cout << "failure" << std::endl;
            return;
        }
        prevNodes.push_back(current);
        current = current->children[index];
    }

    bool checkLeaf = isLeaf(current);
    current->isWord = false;
    if (!checkLeaf) {
        size--;
        std::cout << "success" << std::endl;
        return;
    } else {
        for (int i = len; i >= 0; i--) {
            int index = word[i] - 'A';
            TreeNode* node = prevNodes[i];
            
            //checks to see wehther the prev node is a leaf or not
            node->children[index]->isLeaf = isLeaf(node->children[index]);
            if (node->children[index]->isWord || !node->children[index]->isLeaf) {
                // Node has children, cannot be deleted
                break;
            }
            delete node->children[index];
            node->children[index] = nullptr;
        }
        size--;
        std::cout << "success" << std::endl;
    }
}

void Trie::print(TreeNode* node, std::string output) {
    if (node == nullptr) {
        return;
    }

    if (node->isWord) {
        std::cout << output + " ";
    }

    for (int i = 0; i < node->children.size(); i++) {
        char c = 'A' + i; // get the char at the index
        print(node->children[i], output + c);
    }
}

void Trie::spellcheck(std::string word) {
    current = root;
    std::string output = "";

    for (char c : word) {
        int index = c - 'A';

        if (current->children[index] == nullptr) {
            if(current == root) {
                return;
            }
            print(current, output);
            return;
        }
        output += c;
        current = current->children[index];
    }

    if (current->isWord) {
        std::cout << "correct";
        return;
    }

    if (current != nullptr) {
        print(current, output);
    }
}


std::string Trie::empty() {
    if (size == 0) {
        return "empty 1";
    } else {
        return "empty 0";
    }
}

void Trie::clear(TreeNode*& node) {
    size = 0;
    if (node == nullptr) {
        return;
    }
    for (int i = 0; i < node->children.size(); i++) {
        clear(node->children[i]);
    }
    
    if (node != root) {
        delete node;
        node = nullptr;
    }
}

int Trie::getSize() {
    return size;
    // int count = 0;

    // if (node == nullptr) {
    //     return 0;
    // }

    // if (node->isWord) {
    //     count++;
    // }

    // for (int i = 0; i < node->children.size(); i++) {
    //     count += size(node->children[i]);
    // }
    // return count;
}
