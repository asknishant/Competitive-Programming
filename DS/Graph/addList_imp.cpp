#include <iostream>
#include <list>

using namespace std;
class Graph {
    int V;  //no of vertices
    list<int> *l;
public:

    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool bidir = true) {
        l[x].push_back(y);
        if(bidir) {
            l[y].push_back(x);
        }
    }   

    void print() {
        for(int i=0;i<V;i++) {
            cout << "Vertex " << i << "-->";
            for(auto v : l[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

};

int main() {

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);

    g.print();
    return 0;
}
