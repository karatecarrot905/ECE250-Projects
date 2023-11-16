#include <iostream>
#include <fstream>
#include <cmath>
#include "tree_node.h"
#include "trie.h"
#include "illegal_exception.h"
using namespace std;


int main () {
    string cmd;
    string val;

    Trie myTrie;
    ifstream fin("corpus.txt");

    while (cin >> cmd) 
    {
        if (cmd == "load")
        {
            while (fin>>val) {
                myTrie.insertCorpus(val);
            }
            std::cout << "success" << std::endl;
        }
        else if (cmd == "i")
        {
            try {
                cin >> val;
                for (int i = 0; i < val.length(); i++) {
                    if (val[i] < 65 || val[i] > 90) {
                        throw illegal_exception();
                    }
                }
                myTrie.insert(val);
            } catch(illegal_exception e) {
                std::cout << "illegal argument" << std::endl;
            }
        }
        else if (cmd == "c")
        {
            try {
                cin >> val;
                for (int i = 0; i < val.length(); i++) {
                    if (val[i] < 65 || val[i] > 90) {
                        throw illegal_exception();
                    }
                }

                int NUM = myTrie.prefix(val);
                if (NUM == 0) {
                    std::cout << "not found" << std::endl;
                } else {
                    std::cout << "count is " << NUM << std::endl;
                }

            } catch(illegal_exception e) {
                std::cout << "illegal argument" << std::endl;
            }
        }
        else if (cmd == "e")
        {
            try {
                cin >> val;
                for (int i = 0; i < val.length(); i++) {
                    if (val[i] < 65 || val[i] > 90) {
                        throw illegal_exception();
                    }
                }
                myTrie.erase(val);
            } catch(illegal_exception e) {
                std::cout << "illegal argument" << std::endl;
            }
        }
        else if (cmd == "p")
        {
            myTrie.print(myTrie.root, "");
            if (myTrie.getSize() != 0) {
                std::cout << '\n';
            }
        }
        else if (cmd == "spellcheck")
        {
            cin >> val;
            myTrie.spellcheck(val);
            std::cout << '\n';
        }
        else if (cmd == "empty")
        {
            std::cout << myTrie.empty() << std::endl;
        }
        else if (cmd == "clear")
        {
            myTrie.clear(myTrie.root);

            std::cout << "success" << std::endl;
        }
        else if (cmd == "size")
        {
            std::cout << "number of words is " << myTrie.getSize() << std::endl; 
        }
        else if (cmd == "exit")
        {
            if(myTrie.getSize() != 0) {
                myTrie.clear(myTrie.root);
            }
            delete myTrie.root;
            return 0;
        }
    }
};
