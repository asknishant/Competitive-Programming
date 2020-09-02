#include <iostream>
#include <unordered_map>
#include <cstring>
#include <list>;

using namespace std;

class Graph {
    int V;
    unordered_map<string, list<pair<string, int> > > l; 

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(string x, string y, bool bidir, int wt) {
        //Here we are adding pair of y and wt to the list.
        l[x].push_back(make_pair(y,wt));
        if(bidir) {
            l[y].push_back(make_pair(x,wt));
        }
    }

    void printAdjList() { 
        for(auto mp: l) {
           cout << mp.first << "-->";
           list<pair<string,int> > lst = mp.second;

           for(auto v : lst) {
               cout  << " " << v.first << "," << v.second;
           }
           cout << endl;
        }
    }

};


int main() {

    Graph g(4);

    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    
    g.printAdjList();   //Printing will be unordered as we have used unordered map.
}
