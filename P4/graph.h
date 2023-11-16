#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <tuple>

class Graph {
    public:
        void insert(int a, int b, int w);

        void print(int a);

        void remove(int a);

        std::vector<std::tuple<int, int, int>> mst();
        
        int cost();

        void setSize(int size);

        void loadInsert(int a, int b, int w);

    private:
        std::vector<std::vector<std::tuple<int, int>>> adjList;
        int totalCost;    
};

#endif