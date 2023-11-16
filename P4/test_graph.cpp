#include <iostream>
#include <fstream>
#include <cmath>
#include "graph.h"
#include "illegal_exception.h"
using namespace std;


int main () {
    string cmd;
    int val;
    int a;
    int b;
    int w;

    Graph g;

    ifstream fin("bigGraph.in");

    while (cin >> cmd) 
    {
        if (cmd == "LOAD")
        {
            string fName;
            cin >> fName;
            ifstream fin(fName.c_str());

            fin >> val;
            g.setSize(val);

            while (fin >> a) { // this reads the text file word by word
                // first val will be the size, so resize to the val
                // next will be INSERT vals
                val = 1;
                while (val == 1) {
                    fin >> b;
                    fin >> w;
                    g.loadInsert(a, b, w);
                    val = 0;
                }
            }
            std::cout << "success" << std::endl;
        }
        else if (cmd == "INSERT")
        {
            try {
                cin >> a;
                cin >> b;
                cin >> w;
                if (a <= 0 || a > 50000 || b <= 0 || b > 50000 || w <= 0) {
                    throw illegal_exception();
                }
                g.insert(a, b, w);
            } catch(illegal_exception e) {
                std::cout << "illegal argument" << std::endl;
            }
        }
        else if (cmd == "PRINT")
        {
            try {
                cin >> a;
                if (a <= 0 || a > 50000) {
                    throw illegal_exception();
                }
                g.print(a);
            } catch(illegal_exception e) {
                std::cout << "illegal argument" << std::endl;
            }
        }
        else if (cmd == "DELETE")
        {
            try {
                cin >> a;
                if (a <= 0 || a > 50000) {
                    throw illegal_exception();
                }

                g.remove(a);
            } catch(illegal_exception e) {
                std::cout << "illegal argument" << std::endl;
            }
        }
        else if (cmd == "MST")
        {
            std::vector<std::tuple<int, int, int>> mstList;
            mstList = g.mst();

            if (mstList.size() <= 0) {
                std::cout << "failure" << std::endl;
            } else{
                for (auto& edge : mstList) {
                    std::cout << get<0>(edge) << " " << get<1>(edge) << " " << get<2>(edge) << " ";
                }
                std::cout << '\n'; 
            }

        }
        else if (cmd == "COST")
        {
            std::cout << "cost is " << g.cost() << std::endl;
        }
        else if (cmd == "END")
        {
            return 0;
        }
    }
};
