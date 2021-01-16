#include<bits/stdc++.h>
using namespace std;


bool dfs_helper(int node,int parent,vector<int> graph[],int color,int visited[]) {
    visited[node] = color;  // both 1 and 2 means visited
    for(auto nbr : graph[node]) {
        if(!visited[nbr]) {
            bool subprob = dfs_helper(nbr,node,graph,3-color,visited);
            if(subprob == false) {
                return false;
            }
        } else if(nbr != parent and color == visited[nbr]) {
            return false;
        }
    }
    return true;
}   
bool dfs(vector<int> graph[],int N) {
    int visited[N] = {0};
   
    int color = 1;
    return dfs_helper(0,-1,graph,color,visited);
}
int main() {

    #ifndef ONLINE_JUDGE 
  
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
  
    #endif 

    int N;
    cin >> N;

    vector<int> graph[N];   //An array of vectors

    int edges;
    cin >> edges;

    int x,y;
    while(edges--) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if(dfs(graph,N)) {
        cout << "Bipartite graph";
    } else{
        cout << " Non bipartite";
    }

    return 0;
}
