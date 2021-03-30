#include<iostream>
#include<queue>

//Givenn N ropes of different sizes ,
//We have to join them together.Cost of joining two ropes
//is A + B.Find the minimum cost to join all the ropes.

using namespace std;
int join_ropes(int ropes[],int n) {
	priority_queue<int,vector<int>,greater<int> > pq(ropes, ropes+n);
	int cost = 0;
	while(pq.size() > 1) {
		//Take two minm elements.
		int A = pq.top();
		pq.pop();
		int B = pq.top();
		pq.pop();

		cost += (A+B);
		pq.push(A+B);
	}
	return cost;
}

int main() {

	 #ifndef ONLINE_JUDGE 
  
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
  
    #endif 
	int ropes[] = {4,3,2,6};
	int n = 4;

	cout << join_ropes(ropes,n);
} 
