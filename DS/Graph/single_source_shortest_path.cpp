//Single source shortest path.
//Note:-Distance travelled by level order traversal is the shortest(Given no weights of edges).
        //When weights are given it is Dijkitra algo.

#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;

template<typename T>
class Graph {

    int V;
    map<T,list<T> > mp;
public:
    Graph(int v) {
        V = v;
    }
    void addEdge(T x, T y) {
        mp[x].push_back(y);
        mp[y].push_back(x);
    }


    void bfs(int src) {

        queue<T> q;
        map<T,int> dist;

        q.push(src);


        //Keeping all nodes at infinity except 0;
       
        for(auto node_pair:mp) {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0;

        while(!q.empty()) {
            
            T node = q.front();
            q.pop();
            for(auto nbr:mp[node]) {
                if(dist[nbr]==INT_MAX) {    //if the node is visited for the first time.
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }  
            }
        }

        for(auto node_pair:mp) {
            T node = node_pair.first;
            cout << "Node " << node << " Distance from source " << dist[node] <<endl; 
        }
    }  

};      

int main() {
    
    Graph<int> g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(0,3);
    g.addEdge(4,5);

    g.bfs(0);
}
