#include<bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<pair<int,int> > *l;
public:

	Graph(int V) {
		this->V = V;
		l = new vector<pair<int,int> >[V]; 
	}
	void addEdge(int x,int y,int w) {
		l[x].push_back({w,y});
		l[y].push_back({w,x});
	}	

	int prim_mst() {
		//min heap whose elements are pairs.
		priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int> > >pq;

		///An array to check whether a node is included in MST or not.
		bool *visited = new bool[V]{0};
		int ans = 0;
		pq.push({0,0});
		while(!pq.empty()) {
			pair<int,int> best = pq.top();
			pq.pop();

			int w = best.first;
			int node = best.second;

			if(visited[node]) {	//If the node is already in your MST set.
				continue;
			}

			//Otherwise take the current edge.
			ans += w;
			visited[node] = true;

			//Add the new edges to the priority queue.
			for(auto x : l[node]) {
				if(!visited[x.first]) {
					pq.push({x.second,x.first});
				}
			}
		}

		return  ans;
	}



};	

int main() {


	#ifndef ONLINE_JUDGE 
  
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
  
    #endif 


    Graph g(4);

    g.addEdge(0,1,1);
    g.addEdge(0,2,2);
    g.addEdge(0,3,2);
    g.addEdge(1,3,3);
    g.addEdge(2,3,3);
    g.addEdge(1,2,2);

    cout << g.prim_mst();



	return 0;
}
