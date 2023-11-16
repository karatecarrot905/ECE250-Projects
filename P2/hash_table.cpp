#include <iostream>
#include <vector>
#include <cmath>
#include "hash_table.h"
#include "hash_node.h"

HashTable::HashTable() {
}

void HashTable::setSize(unsigned int size, int pages) {
    HashTable::pages = pages;
    HashTable::m = size;
    hash_table_size = size;
    table.resize(hash_table_size);
    for (int i = 0; i < hash_table_size; i++) {
        table[i] = nullptr;
    }
}

int HashTable::primaryHashFunction(const unsigned int& pid) {
    return pid % hash_table_size;
}

int HashTable::secondaryHashFunction(const unsigned int& pid) {
    int hashkey = (pid / hash_table_size) % hash_table_size;

    if ((hashkey % 2) == 0) {
        return ++hashkey;
    } else {
        return hashkey;
    }
}

void HashTable::insert(const unsigned int& pid) {
    int hashkey = primaryHashFunction(pid);
    int page = 0;

    if (search(pid) == -1 && (m > 0) && page < pages) {
        prev = nullptr;
        HashNode* entry = table[hashkey];
        while (entry != nullptr && entry->key != pid) {
            prev = entry;
            entry = entry->next;
            pages++;
        }

        if (entry == nullptr) {
            entry = new HashNode(pid, pages);
            if (prev == nullptr) {
                table[hashkey] = entry;
            } else {
                prev->next = entry;
            }
            m--;
            std::cout << "success" << std::endl;
        }
    } else {
        std::cout << "failure" << std::endl;
    }
}


int HashTable::search(const unsigned int& pid) {
    int p = 0;
    prev = nullptr;
    for (int i = 0; i < hash_table_size; i++) {
        current = table[i];
        while (current != nullptr) {
            if (current->key == pid) {
                if (p == 0) {
                    return i;
                } else {
                    return p;
                }
            } else {
                p++;
            }
            prev = current;
            current = current->next;
        }
    }
    return -1;
}

void HashTable::write(const unsigned int& pid, unsigned int addr, int x) {
    int i = 0;
    if (search(pid) != -1) {
        int hashkey = primaryHashFunction(pid);
        HashNode* entry = table[hashkey];
        //prev = nullptr;

        while (entry->key != pid) {
           // i++;
            entry = entry->next;
        }

        if (addr < pages) {
            entry->value = addr;
            entry->array_ptr[addr] = x;
            // array[hashkey] = x;
            std::cout << "success" << std::endl;
        } else {
            std::cout << "failure" << std::endl;
        }
    } else {
        std::cout << "failure" << std::endl;
    }
}

void HashTable::read(unsigned int pid, unsigned int addr) {
    int i = 0;
    if (search(pid) != -1) {
        int hashkey = primaryHashFunction(pid);
        HashNode* entry = table[hashkey];

        while (entry->key != pid) {
            entry = entry->next;
            //i++;
        }

        if (addr < pages) {
           std::cout << addr << " " << entry->array_ptr[addr]<< std::endl;
        } else {
            std::cout << "failure" << std::endl;
        }
    } else {
        std::cout << "failure" << std::endl;
    }
}

void HashTable::remove(const unsigned int& pid) {
    int hashkey = search(pid);

    if (hashkey != -1) {
        if (prev == nullptr) {
            table[hashkey] = current->next;
        } else {
            prev->next = current->next;
        }
        m++;
        delete current;
        std::cout << "success" << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }

}

void HashTable::print(int m) {
    current = table[m];
    // current = table[m];
    // HashNode* entry = current;

    int index = 0;
    std::string chain;

    if (current == nullptr) {
        std::cout << "chain is empty" << std::endl;
    } else {
        HashNode* next = nullptr;
        int temp;

        while (current->next != nullptr) {
            next = current->next;
            while (next != nullptr) {
                if (current->key < next->key) {
                    temp = current->key;
                    current->key = next->key;
                    next->key = temp;
                }
                next = next->next;
            }
            current = current->next;
        }

        current = table[m];
        while (current != nullptr) {
            std::cout << current->key << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}


HashTable::~HashTable() {
    for (int i = 0; i < hash_table_size; i++) {
        HashNode* entry = table[i];
        while (entry != nullptr) {
            HashNode* next = entry->next;
            delete entry->array_ptr;
            delete entry;
            entry = next;
        }
    }
}


