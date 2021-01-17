//Dijkistra's algorithm
//Single source shortest path
//O(N*2)-For complete graph as each vertex is going to relax all n veticces if |V| = n

//IT is greedy approach.It may work or may not for negative weights
//IF u is a node pointing to v then relaxation = (d[u]+c[u,v] < d[v]) => d[v] = d[u]+c[u,v].

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
    map<T,list<pair<T,int> > > m;
public:

    void addEdge(T u,T v,int dist,bool bidir = true) {
        m[u].push_back(make_pair(v,dist));
        if(bidir) {
            m[v].push_back(make_pair(u,dist));
        }
    }

    void printAdj() {
        for(auto mp:m) {
            T x = mp.first;
            cout << x << "-->";

            for(auto y:mp.second) {
                cout << "( " << y.first <<"," << y.second << " )";
            }
            cout << endl;
        }
    }

    void dijkistra(T src) {
        unordered_map<T,int> dist;
        for(auto j:m) {
            dist[j.first] = INT_MAX;
        }

        set<pair<int,T> > s;///Set is created with first parameter as int as its sorting is done on the basis of first parameter.
        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty()) {

            //Finding the front element           
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first; 
            s.erase(s.begin());

            //Iterate over the children of the current node.
            for(auto childPair:m[node]) {
                if(nodeDist+childPair.second < dist[childPair.first]) {

                    //In the set/priority queue updation of the node is not possible.
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()) {//If the node has been found..
                        s.erase(f);
                    }

                    //Insert the new dist;
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest],dest)); 
                }
            }
        }
        //print final distance map from source
        for(auto distance : dist) {
            cout << distance.first << " is located at " << distance.second << endl;
        }
    }
};
int main() {

Graph<int> g;
g.addEdge(1,2,1);
g.addEdge(1,3,4);
g.addEdge(2,3,1);
g.addEdge(3,4,2);
g.addEdge(1,4,7);

g.printAdj();
g.dijkistra(1);
}
