// Representation of graph using linked lists.


#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int V;
    
    //Array of pointers each of whose members are pointing to a linked list of nodes.(NOte: We could have created a 2D array dynamically int** a = new int*[v]).
    list<int>* adjList; //list in STL denotes linked list,
    Graph(int v) {
        V = v;;
        adjList = new list<int>[v];
    }
    

    void addEdges(int f, int s, bool bidir = true) 
     {
        ///Here we are creating a function to create an edge between nodes
        // which takes first and last nodes and where nodes are bidirectional.
        
        adjList[s].push_back(f);
        if(bidir) {
            adjList[f].push_back(s);
        }
     }
     void printAdjList() {
         for(int i=0;i<V;i++) {
             cout << i << "->";
             for(int node : adjList[i]) {
                 cout << node << ",";
             }
             cout << endl;
         }
         delete adjList;
     }

};
int main(void) {
    cout << "Enter no of nodes ";
    int v;  cin >> v; //v for vertices
     Graph g(v);

    for(int i=0;i<v;i++) {
        int f,s;
        cin >> f >> s;
        g.addEdges(f,s);
    }

    g.printAdjList();
    return 0;
}
