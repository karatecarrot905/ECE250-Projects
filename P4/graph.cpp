#include <iostream>
#include <vector>
#include <tuple>
#include "graph.h"
using namespace std;

void Graph::setSize(int size) {
    adjList.resize(size + 1);
}

void Graph::loadInsert(int a, int b, int w) {
    if (adjList.size() <= b || adjList.size() <= a) {
        if (a > b) {
            adjList.resize(a + 1);
        } else {
            adjList.resize(b + 1);
        }
    }
    adjList[a].push_back(make_tuple(b, w));
    adjList[b].push_back(make_tuple(a, w));
}

void Graph::insert(int a, int b, int w) {
    int originalSize = adjList.size();

    if (adjList.size() <= b || adjList.size() <= a) {
        if (a > b) {
            adjList.resize(a + 1);
        } else {
            adjList.resize(b + 1);
        }
    }

    if (adjList.size() > 0) {
        for(auto& edge : adjList[a]) {
            if (get<0>(edge) == b) {
                adjList.resize(originalSize);
                cout << "failure" << endl;
                return;
            }
        }
    }

    adjList[a].push_back(make_tuple(b, w));
    adjList[b].push_back(make_tuple(a, w));

    cout << "success" << endl;
    
}

void Graph::print(int a) {
    if (a >= adjList.size() || adjList[a].size() <= 0) {
        cout << "failure" << endl;
        return;
    } 
    for (tuple<int, int>& i : adjList[a]) {
        cout << get<0>(i) << " ";
    }

    cout << '\n';
}
    
void Graph::remove(int a){
    // rempve the edges containing vertex a
     if (a >= adjList.size() || adjList[a].size() <= 0) {
        cout << "failure" << endl;
        return;
    }
    for (int i = 0; i < adjList.size(); i++) {
        vector<tuple<int, int>> list;
        for (tuple<int, int>& edge : adjList[i]) {
            if (get<0>(edge) != a) {
                // if edge contains vertex a, it will not be added to the updated list
                list.push_back(edge);
            }
        }
        adjList[i] = list;
    }

    adjList[a].clear();
    cout << "success" << endl;
}

vector<tuple<int, int, int>> Graph::mst() {
    // use the kruskal method
    totalCost = 0;
    vector<tuple<int, int, int>> mstList;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < adjList.size(); i++) {
        for (tuple<int, int> v : adjList[i]) {
            if (get<0>(v) > i) {
                // ensures no repeated edges
                // weight is the first element in the tuple
                edges.push_back(make_tuple(get<1>(v), i, get<0>(v)));
            }
        }
    }

    //sort the weights
    // not sorting properly
    int n = edges.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (get<0>(edges[j]) > get<0>(edges[j + 1])) {
                auto temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // initialize the disjoint set
    vector<int> parent(adjList.size());
    for (int i = 0; i < parent.size(); i++) {
        parent[i] = i;
    }

    for (auto edge : edges) {
        int w = get<0>(edge);
        int a = get<1>(edge);
        int b = get<2>(edge);


        while (parent[a] != a) a = parent[a];
        while (parent[b] != b) b = parent[b];
        if (a == b) {
            continue;
        }

        mstList.push_back(make_tuple(a, b, w));
        totalCost += w;
        parent[a] = b;

    }

    return mstList;
}

int Graph::cost() {
    mst();
    return totalCost;
}