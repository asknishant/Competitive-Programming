#include<bits/stdc++.h>
using namespace std;


class DSU {
public: 
	int V;
	int *parent;
	int *rank;

	DSU(int V) {
		this->V = V;
		parent = new int[V];
		rank = new int[V];
		for(int i=0;i<V;i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}
	int find_set(int x) {
		if(parent[x] == -1) {
			return x;
		}

		return parent[x] = find_set(parent[x]);
	}

	void union_set(int x,int y) {
		int s1 = find_set(x);
		int s2 = find_set(y);

		if(s1 != s2) {
			if(rank[s1] > rank[s2]) {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			} else{
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
		}
	}

};

//Creating a graph represented by edgelist not by adjacency list as we are greedy about the edges to find MST using kruskal's algo
class Graph {

public:
	int V;
	vector<vector<int> > edgelist;
	Graph(int V) {
		this->V =V;
	}

	void addEdge(int x,int y,int wt) {
		edgelist.push_back({wt,x,y});//As we have to sort according to the weights of the edges
	}

	//Too easy algo
	int kruskal_mst() {
		//We will be using greedy method to get the edge with the smallest cost.
		//For that we will sort our edgelist
		//After sorting we will sum up the top list of edges for which our graph is not cyclic i.e forms MST.

		sort(edgelist.begin(),edgelist.end());
		DSU s(V);

		int ans = 0;
		for(auto edge : edgelist) {
			int weight = edge[0];
			int node1 = edge[1];
			int node2 = edge[2];

			//If cycle is not present
			if(s.find_set(node1) != s.find_set(node2)) {
				s.union_set(node1,node2);
				ans += weight;
			}
		}
		return ans;
	}
};

int main() {


	#ifndef ONLINE_JUDGE 
  
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
  
    #endif 


	Graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(1,3,3);
	g.addEdge(3,2,4);
	g.addEdge(2,0,2);
	g.addEdge(0,3,2);
	g.addEdge(1,2,2);

	cout << g.kruskal_mst() << endl;


	return 0;
}
