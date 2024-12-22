#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

using namespace std;

struct Edge {
    string destination;
    Edge* nextEdge;
};

struct Node {
    string name;
    Edge* firstEdge;
    Node* nextNode;
};

struct Graph {
    Node* start;
};

void createGraph(Graph& G);
Node* allocateNode(const string& name);
Edge* allocateEdge(const string& destination);
void addNewNode(Graph& G, const string& name);
void connectNodes(Graph& G, const string& src, const string& dest);
void showGraphToMall(const string rute[], int size);
string findShortestMall(const string malls[], const int distances[], int size);
void findShortestPathWithAvoid(const string malls[], const string rutes[][5], const int ruteSizes[], int mallCount, const string& avoidArea);

#endif

