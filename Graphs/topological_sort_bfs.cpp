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
    
    void addEdge(int x,int y){
        //it is not bidir
        l[x].push_back(y);
    }

    void topological_sort_bfs() {
        int *indegree = new int[V];
        queue<int> q;

        for(int i=0;i<V;i++) {
            indegree[i] = 0;
        }

        for(int i=0;i<V;i++) {
            for(auto nbr:l[i]) {
                indegree[nbr]++;
            }
        }

        for(int i=0;i<V;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        //Start removing indegrees from the queue.
        while(!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop(); 

            //Iterate over the neighbours and reduce the indegrees by 1.
            for(auto nbr:l[node]) {
                indegree[nbr]--;
                if(indegree[nbr]==0) {
                    q.push(nbr);
                }
            }
        }
    }
};
int main() {
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(3,5);

    g.topological_sort_bfs();
}
