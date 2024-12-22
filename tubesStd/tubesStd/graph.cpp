#include "graph.h"

void createGraph(Graph& G) {
    G.start = nullptr;
}

Node* allocateNode(const string& name) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->firstEdge = nullptr;
    newNode->nextNode = nullptr;
    return newNode;
}

Edge* allocateEdge(const string& destination) {
    Edge* newEdge = new Edge;
    newEdge->destination = destination;
    newEdge->nextEdge = nullptr;
    return newEdge;
}

void addNewNode(Graph& G, const string& name) {
    Node* newNode = allocateNode(name);
    if (!G.start) {
        G.start = newNode;
    } else {
        Node* temp = G.start;
        while (temp->nextNode) temp = temp->nextNode;
        temp->nextNode = newNode;
    }
}

void connectNodes(Graph& G, const string& src, const string& dest) {
    Node* srcNode = G.start;
    while (srcNode && srcNode->name != src) {
        srcNode = srcNode->nextNode;
    }

    if (srcNode) {
        Edge* newEdge = allocateEdge(dest);
        newEdge->nextEdge = srcNode->firstEdge;
        srcNode->firstEdge = newEdge;
    }
}

void showGraphToMall(const string rute[], int size) {
    cout << "\nIlustrasi Rute:\n";
    for (int i = 0; i < size; i++) {
        cout << rute[i];
        if (i < size - 1) cout << " -> ";
    }
    cout << " (akhir)\n";
}

string findShortestMall(const string malls[], const int distances[], int size) {
    int minDistance = INT_MAX;
    string nearestMall = "";

    for (int i = 0; i < size; ++i) {
        if (distances[i] < minDistance) {
            minDistance = distances[i];
            nearestMall = malls[i];
        }
    }

    return nearestMall.empty() ? "Tidak ada mall terdekat." : nearestMall;
}

void findShortestPathWithAvoid(const string malls[], const string rutes[][5], const int ruteSizes[], int mallCount, const string& avoidArea) {
    bool found = false;
    cout << "\nMall yang tidak melewati " << avoidArea << ":\n";

    for (int i = 0; i < mallCount; ++i) {
        bool avoid = false;

        // Cek apakah rute mall ini melewati wilayah yang dihindari
        for (int j = 0; j < ruteSizes[i]; ++j) {
            if (rutes[i][j] == avoidArea) {
                avoid = true;
                break; // Langsung berhenti jika wilayah ditemukan
            }
        }

        // Jika tidak melewati wilayah, tampilkan mall
        if (!avoid) {
            cout << "- " << malls[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Tidak ada mall yang bisa dikunjungi tanpa melewati " << avoidArea << ".\n";
    }
}

