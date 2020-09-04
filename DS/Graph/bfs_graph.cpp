//Breadth first search


#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;

template<typename T>
class Graph {
    T V;
    map <T, list<T> > mp;
public:
    Graph(T v) {
        v = V;
    }

    void addEdge(int x,int y) {
        mp[x].push_back(y);
        mp[y].push_back(x);   
    }

    void bfs(T src) {

        queue<T> q;
        map<T,bool> visited;

        q.push(src);
        visited[src] = true;   

        while(!q.empty()) {
            T node = q.front();
            q.pop();
            cout << node << " ";
            
            for(auto nbr:mp[node]) {
                if(!visited[nbr]) {
                   q.push(nbr);
                   visited[nbr] = true;
                }
            }
        }
    }
};
int main( ) {

    Graph<int> g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.bfs(0);
    return 0;
}
