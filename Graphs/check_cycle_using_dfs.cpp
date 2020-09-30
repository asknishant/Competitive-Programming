#include <bits/stdc++.h>
using namespace std;


class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x,int y,bool bidir) {
        l[x].push_back(y);
        if(bidir) {
            l[y].push_back(x);
        }
    }
    bool cycle_helper(int node,bool *visited,bool *stack) {
        visited[node] = true;
        for(auto nbr:l[node]) {
            if(stack[nbr] == true) {
                return true;
            }
            else if(visited[nbr] == false) {
                visited[nbr] = true;
                bool cycle_mila = cycle_helper(nbr, visited, stack);
                if(cycle_mila) {
                    return true;
                }
            }
        }
        
        //If either cycle not found or no next nbr is found
        //pop that nbr from stack
        stack[node] = false;
        return false;
    }

    bool checkCycleBfs() {
        bool visited[V];
        bool stack[V];

        for(int i=0;i<V;i++) {
            visited[i] = stack[i] = false;
        }

        if(cycle_helper(0,visited,stack)) {
            return true;
        }

        return false;
    }
};
int main() {

    Graph g(6);
    g.addEdge(0,1,false);
    g.addEdge(1,5,false);
    g.addEdge(5,6,false);
    g.addEdge(1,2,false);
    g.addEdge(2,3,false);
    g.addEdge(3,4,false);
    g.addEdge(4,5,false);

    if(g.checkCycleBfs()) {
        cout << "Cycle is present";
    }else {
        cout << "Cycle not present";
    }
    


    return 0;
}
