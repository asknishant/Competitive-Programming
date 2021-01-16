#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[],int i,bool visited[],vector<int> &stack) {
    visited[i] = true;
    for(auto nbr : graph[i]) {
        if(!visited[nbr]) {
            dfs(graph,nbr,visited,stack);
        }
    }

    //Function call is complete.
    stack.push_back(i);
}

void dfs2(vector<int> rev_graph[],int node,bool visited[]) {
    visited[node] = true;
    cout<< node << " ";
    for(auto nbr : rev_graph[node]) {
        if(!visited[nbr]) {
            dfs2(rev_graph,nbr,visited);
        }
    }
}
void solve(vector<int> graph[],vector<int> rev_graph[],int N) {
    bool visited[N];
    memset(visited,false,N);

    vector<int> stack;

    for(int i=0;i<N;i++) {
        if(!visited[i]) {
            dfs(graph,i,visited,stack);
        }
    }

    //Now we have the ordering .b
    //Do dfs acc to the ordering of nodes in the stack.


    memset(visited,false,N);
    int component = 0;
    for(int x = stack.size()-1;x>=0;x--) {
        int node = stack[x];

        if(!visited[node]) {
            //There is a component starting from this node.
            cout << "component " << component << "-->"; 
            dfs2(rev_graph,node,visited);
            cout << endl;
            component++;
        }
    } 
}


int main() {

    #ifndef ONLINE_JUDGE 
  
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
  
    #endif 

    int N;
    cin >> N;

    vector<int> graph[N];   //An array of vectors
    vector<int> rev_graph[N];

    int edges;
    cin >> edges;

    int x,y;
    while(edges--) {
        cin >> x >> y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }

    solve(graph,rev_graph,N);

    return 0;
}
