//https://www.youtube.com/watch?v=MTsvJUwZdS4&t=3098s

//Graph using Hashmaps.Hashmaps is a data structure to store key value pairs.
//C++ uses maps or unordered map from stl to store these key value pairs.

#include <bits/stdc++.h>
using namespace std;

class Graph {
  map<string,list<string> > adjList;

  public: 
    Graph() {

    }

    void addEdge(string f,string s,bool bidir=true) {
      adjList[f].push_back(s);
      if(bidir) {
        adjList[s].push_back(f);
      }
    }

    void printAdjList() {
      for(auto row : adjList) {
        string key = row.first;
        cout << key <<"->";

        for(string element : row.second) {
          cout << element << " ";
        }
        cout << endl;
      }

    }
};

int main(void) {

  Graph g;
  g.addEdge("Amritsar" ,  "Delhi");
  g.addEdge("Amritsar", "Jaipur");
  g.addEdge("Delhi" , "Siachen");
  g.addEdge("Delhi" , "Bangalore");
  g.addEdge("Delhi" ,  "Agra");
  g.addEdge("Amritsar" , "Siachen");

  g.printAdjList();
  return 0;
}
