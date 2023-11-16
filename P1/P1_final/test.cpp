#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    double value;
    string name;
    Node* next;

    Node(double value, string name) {
        this->value = value;
        this->name = name;
        this->next = nullptr;
    }
};

class LinkedList {
public:

    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() { clear(); } 

    bool searchByName(string name) {
        before = nullptr;
        current = head;

        while (current != nullptr) {
            if (current->name == (name)) {
                return true;
            }
            before = current;
            current = current->next;
        }
        return false;
    }

    void insert(double value, string name) {
        if (head == nullptr){
            head = new Node(value, name);
            std::cout << "success" << std::endl;
            size--;
        }
        else if (!searchByName(name) && size != 0) {
            Node* newNode = new Node(value, name);
            newNode->next = head;
            head = newNode;
            size--;
            std::cout << "success" << std::endl;
        } else {
            std::cout << "failure" << std::endl;
        }
    }

    void remove(string name) {
        
        if (searchByName(name)) {

            if (before == nullptr) {
                head = current->next;
            } else {
                before->next = current->next;
            }
            delete current;
            std::cout << "success" << std::endl;
            size++;
            return;
        } else {
            std::cout << "failure" << std::endl;
        }
    }

    void add(string var1, string var2, string name) {
        Node* val1;
        Node* val2;

        if (searchByName(var1)) {
            val1 = current;
        }

        if(searchByName(var2)) {
            val2 = current;
        }

        if (searchByName(name) && searchByName(var1) && searchByName(var2)) {
            searchByName(name);
            current->value = (val1->value) + (val2->value);
            std::cout << "success" << std::endl;
            return;
        } else {
            std::cout << "failure" << std::endl;
            return;
        }
    }

    void sub(string var1, string var2, string name) {
        Node* val1;
        Node* val2;

        if (searchByName(var1)) {
            val1 = current;
        }

        if(searchByName(var2)) {
            val2 = current;
        }

        if (searchByName(name) && searchByName(var1) && searchByName(var2)) {
            searchByName(name);
            current->value = (val1->value) - (val2->value);
            std::cout << "success" << std::endl;
        } else {
            std::cout << "failure" << std::endl;
        }
    }

    void prt(string name) {
        if(searchByName(name)) {
            std::cout << current->value << std::endl;
        } else {
            std::cout << "variable " << name << " not found" << std::endl;
        }
    }

    void clear() {
        while (head != nullptr) {
            current = head;
            head = head->next;
            delete current;
        }
        size = 0;
    }

    void setSize(int size) {
        LinkedList::size = size;
    }

private:
        Node* head;
        Node* before;
        Node* current;
        int size;
};

int main () {
    string cmd;
    double val;
    string name;
    string var1;
    string var2;

    LinkedList calculator;

    while (cin >> cmd) 
    {
        if (cmd == "CRT")
        {
            cin >> val;
            calculator.setSize(val);
            cout << "success" << endl;
        }
        else if (cmd == "DEF")
        {
            cin >> name;
            cin >> val;
            calculator.insert(val, name);
            
        }
        else if (cmd == "ADD")
        {
            cin >> var1;
            cin >> var2;
            cin >> name;

            calculator.add(var1, var2, name);

        }
        else if (cmd == "SUB")
        {
            cin >> var1;
            cin >> var2;
            cin >> name;

            calculator.sub(var1, var2, name);
        }
        else if (cmd == "REM")
        {
            cin >> name;
            calculator.remove(name);
        }
        else if (cmd == "PRT")
        {
            cin >> name;
            calculator.prt(name);
        }
        else if (cmd == "END")
        {
            calculator.clear();
            return 0;
        }
    }
};
