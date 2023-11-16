#include <iostream>
#include <vector>
#include <cmath>
#include "hash_table.h"
#include "hash_node.h"
using namespace std;

int HASH_TABLE_SIZE;

int main () {
    string cmd;
    unsigned int val;
    unsigned int addr;
    int x;
    int N;
    int P;

    HashTable table;

    while (cin >> cmd) 
    {   
        if (cmd == "OPEN" || cmd == "ORDERED") {
            //continue;
        }
        else if (cmd == "M")
        {
            cin >> N;
            cin >> P;

            HASH_TABLE_SIZE = (N / P);
            table.setSize(HASH_TABLE_SIZE, P);
            cout << "success" << endl;
        }
        else if (cmd == "INSERT")
        {
            cin >> val;
            table.insert(val);
            
        }
        else if (cmd == "SEARCH")
        {
            cin >> val;
            int hashkey = table.search(val);
            if (table.search(val) != -1 ) {
                std::cout << "found " << val << " in " << hashkey << std::endl;

            } else {
                std::cout << "not found" << std::endl;
            }
            
        }
        else if (cmd == "WRITE")
        {
            cin >> val;
            cin >> addr;
            cin >> x;

            table.write(val, addr, x);

        }
        else if (cmd == "READ") {
            cin >> val;
            cin >> addr;

            table.read(val, addr);
        }
        else if (cmd == "DELETE")
        {
            cin >> val;
            table.remove(val);
        }
        else if (cmd == "PRINT")
        {
            cin >> val;
            table.print(val);
        }
        else if (cmd == "END")
        {
            //table.deleteArray();
            return 0;
        }
    }
};
