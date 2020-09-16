#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {

    map<T, list<T> > adjList;
public:
    void addEdge(T x,T y) {
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    void dfs_helper(T src,map<T,bool> &visited) {


        cout << src << " ";
        visited[src] = true;

        for(auto node:  adjList[src]) {     
            if(!visited[node]) {
                dfs_helper(node,visited);
            }
        }

    }

    void dfs() {

        map<T,bool> visited;
        for(auto p:adjList) {
            T node = p.first;
            visited[node] = false;
        }
       
    //Just traverse through the all the adjList.first nodes you will get  the components.
         int cmpts = 0;

        for(auto x:adjList) {
            T node = x.first;
            if(!visited[node]) {
                cout << " Component " << cmpts << "-->";
                dfs_helper(node,visited);
                cmpts++;
                cout << endl;
            }
        }
        
    }

};
int main() {
    
    Graph<int> g;
    //Component 1
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    //Component 2
    g.addEdge(6,7);
    g.addEdge(6,8);

    //Component 3
    g.addEdge(9,9);

    g.dfs();

    return 0;
}
