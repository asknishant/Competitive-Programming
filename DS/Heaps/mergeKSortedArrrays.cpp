#include<iostream>
#include<queue>

//Givenn N ropes of different sizes ,
//We have to join them together.Cost of joining two ropes
//is A + B.Find the minimum cost to join all the ropes.

using namespace std;

typedef pair<int,pair<int,int > > node;
vector<int> mergeKSortedArrays(vector<vector<int> > arr) {
	
	vector<int> result;
	priority_queue<node,vector<node>,greater<node> > pq;
	for(int i = 0; i < arr.size(); i++) {
		pq.push({arr[i][0],{i,0}});
	}

	while(!pq.empty()) {
		node current = pq.top();
		pq.pop();
		int ele = current.first;
		int x = current.second.first;
		int y = current.second.second;

		result.push_back(ele);

		if(y+1 < arr[x].size()) {
		
			pq.push({arr[x][y+1],{x,y+1}});
		}
	}
	return result;
}
int main() {

	  #ifndef ONLINE_JUDGE 
  
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
  
    #endif 

	vector<vector<int> >  arr{
		{2,6,12,15},
		{1,3,14,20},
		{3,5,8,10}
	};

	vector<int> output = mergeKSortedArrays(arr);
	for(auto x:output) {
		cout << x << " ";
	}
	return 0;
}
