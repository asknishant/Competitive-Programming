#include <bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x,int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool cycleHelper(int node,bool *visited, int parent) {
        visited[node] = true;
        
        for(auto nbr : l[node]) {
            if(!visited[nbr]) {
                visited[nbr] = true;
                bool cycle_mila = cycleHelper(nbr, visited, node);//For each nbr of the node we need to check whether the nbr gives a cycle which in turn into recursion.
                if(cycle_mila) {
                    return true;
                }
            }
            //nbr is visited but nbr is not parent of node. 
            else if(visited[nbr] and nbr != parent) {
                return true;
            }
        }
        return false;
    }

    bool checkCycleUndirecteddfs() {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++) {
            visited[i] = false;
        }
        //Cycle helper takes node visited array and the parent of node from whcih it has come.
        return cycleHelper(0,visited,-1);
    }
};
int main() {

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);

    if(g.checkCycleUndirecteddfs()) {
        cout << " Cycle present in the undirected graph";
    } else {
        cout << " No cycle";
    }
    return 0;
}
