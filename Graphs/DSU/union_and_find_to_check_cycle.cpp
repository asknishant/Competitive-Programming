#include<bits/stdc++.h>
using namespace std;


class Graph {
    int V;
    list<pair<int,int> > l;
public:
    Graph(int V) {
        this->V = V;
    }
    void addEdge(int u,int v) {
        //We are not making adjacency list here we are making list of pairs
        l.push_back(make_pair(u,v));
    }

    //findSet
    //O(N)
    int find_set(int i, int parent[]) {
        //This function gives the leader of the set.Leader is the root node.
        if(parent[i]==-1) {
            return i;
        }
        return find_set(parent[i],parent);
    }

    //Union
    //O(N)
    void union_set(int x,int y,int parent[]) {
        int s1 = find_set(x,parent);
        int s2 = find_set(y,parent);

        //Cheking whether the leaders of x and y are same or not.
        if(s1 != s2) {
            parent[s1] = s2;//we can write it as parent[s2] = s1 as well.
        }
    }
    
    //isCycle
    bool is_Cycle() {
        int *parent = new int[V];
        for(int i=0;i<V;i++) {
            parent[i] = -1;
        }

        //iterate over the edge list.
        for(auto edge : l) {
            int i = edge.first;
            int j = edge.second;

            int s1 = find_set(i,parent);
            int s2 = find_set(j,parent);

            if(s1 != s2) {
                union_set(s1,s2,parent);
            } else {
                return true;
            }
        }
         delete [] parent;
            return false;
    }
};
int main() {

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);//Trye removing this edge you will get 0 as output.

    cout << g.is_Cycle() << endl;

    return 0;
}
