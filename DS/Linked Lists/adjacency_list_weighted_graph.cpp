#include <bits/stdc++.h>
using namespace std;

int main() {
	list<pair<int,int> > *l;

	int nodes;	cin >> nodes;
	l = new list<pair<int,int> >[nodes];

	int edges;	cin >> edges;

	for(int i=0;i<edges ;i++) {
		int x,y,wt;
		cin >> x >> y >> wt;
		l[x].push_back(make_pair(y,wt));
		l[y].push_back(make_pair(x,wt));//If Bidirectional.
	}

	for(int i=0;i<nodes;i++) {
		cout <<  i << "->";
		for(auto xp : l[i]) {
			cout << "(" << xp.first << "," << xp.second << "),";
		} 
		cout << endl;
	}
}
