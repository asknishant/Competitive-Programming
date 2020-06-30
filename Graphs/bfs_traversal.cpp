//https://www.youtube.com/watch?v=MTsvJUwZdS4&t=3098s

#include <bits/stdc++.h>
using namespace std;

class Graph {
  public :
  int V;
  list<int>* adjList;
  Graph(int v) {
    V = v;
    adjList = new list<int>[v];
  }

  void addEdge(int f, int s, bool bidir = true) {
    adjList[f].push_back(s);
    if(bidir) {
      adjList[s].push_back(f);
    }
  }
  void printArray() {
    for(int i=0;i<V;i++) {
      cout << i << "->";
      for(auto node : adjList[i]) {
        cout << node << " ";
      }
      cout << endl;
    }
  }
  
  //BFS implemetation ->BFS gives the shortest path.It is same as level order traversal in trees.
  //src is the source.Every bfs needs a source.
  void bfs(int src) {
    queue<int> q;
    bool* visited = new bool[V]{0}; //Array to check whether a node is already visited or not.
    q.push(src);
    visited[src] =true;


    while(!q.empty()) {
      int node = q.front();
      cout << node << " ";
      q.pop();
      for(auto neighbour : adjList[node]) {

        //neighbour gets all the nodes from adjList[node](adjList is dynamic array of linked lists.Nodes are the elements of that array.)
          if(!visited[neighbour]) {
            q.push(neighbour);
            visited[neighbour] = true;
          }
      }
    }
  }
};

int main(void ) {
  cout << "Enter no of vertices";
  int v;
  cin >> v;
  Graph g(v);

  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(0,4);
  g.addEdge(2,4);
  g.addEdge(2,3);
  g.addEdge(3,2);
  g.addEdge(3,5);

  g.bfs(0);
  //g.printArray();
}
