//https://www.youtube.com/watch?v=0XYSdIVY6Ks

#include <bits/stdc++.h>
using namespace std;

void print(int** edges, int n, int sv, bool* visited) {
    //sv is out initial node or starting vertex(sv).
    cout << sv << endl;
    visited[sv] = true; //Marking sv as visited.

    for(int i=0;i<n;i++) {
        //If there is no self loops on vertices,
        if(i == sv) {
            continue;
        }
        if(edges[sv][i] == 1) { 
            if(visited[i])
                continue;
            print(edges, n, i, visited);
        }
    }

}

int main(void) {

    int n,e;
    cin >> n >> e;
    int** edges = new int*[n];  //Dynamic memory allocation.Allocates a 2D array in heap.Remember always to create 2D array dynamically like this.
    for(int i=0; i<n; i++) {
        edges[i] = new int[n];  //Row of pointers pointing to arrays.
        for(int j = 0; j < j; i++) {
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++) {
        int f, s;
        cin >> f >> s;
        for(int j=0;j<n;j++) {
            edges[f][s] = 1;
        }
    }
    //To check whether a node is vidited already we need to create a record of it.
    bool* visited = new bool[n];
    //We need to start from a node. Node with index zero is our initial node.
    for(int i=0;i<n;i++)
        visited[i] = false;

    print(edges, n, 0, visited);

    return 0;
}
