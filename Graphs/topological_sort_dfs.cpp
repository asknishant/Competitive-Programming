
//Topological sort using dfs for directed acyclic graph
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {

    map<T,list<T> > adjList;
   
public: 

    void addEdge(T x, T y) {
        adjList[x].push_back(y);
    }

    void dfs_helper(T src,map<T, bool> &visited, list<T> &ordering) {
        
        //cout << src << " ";
        visited[src] = true;
        for(auto node : adjList[src]) {
            if(!visited[node]) {
                dfs_helper(node,visited,ordering);
            }
        }
        ordering.push_front(src);
    }

    void dfs() {
        map<T,bool> visited;
        list<T> ordering;

        for(auto x:adjList) {
            visited[x.first] = false;       
        }

        for(auto node_pair : adjList) {
            T node = node_pair.first;
            if(!visited[node]) {
                dfs_helper(node,visited,ordering);
            }
        }

        for(auto node: ordering) {
            cout << node << endl;
        }
    }

};
int main() {

    Graph<string> g;
    g.addEdge("Python","Data Preprocessing");
    g.addEdge("Python","Pytorch");
    g.addEdge("Python","ML");
    g.addEdge("Data Preprocessing", "ML");
    g.addEdge("Pytorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","Face Recognition");
    g.addEdge("DataSet","FaceRecognition");

    g.dfs();


    return 0;
}
