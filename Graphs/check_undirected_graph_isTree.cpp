#include<bits/stdc++.h>
using namespace std;

//Check whether an undirected graph is a tree or not.
class Graph {
    list<int>* l;
    int V;
public:

    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x,int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }  

    bool isTree() {
        queue<int> q;
        bool* visited = new bool[V];
        int* parent = new int[V];

        for(int i=0;i<V;i++) {
            visited[i] = false;
            parent[i] = i;
        }

        int src = 0;
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto nbr : l[node]) {
                if(visited[nbr] == true and parent[node] != nbr) {
                    return false;
                }
                else if(!visited[nbr]){
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }

};
int main() {


    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);

    if(g.isTree()) {
        cout << "Its a tree!!!";
    } else {
        cout << " Its not a tree";
    }
    return 0;
}
