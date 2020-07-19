#include <iostream>
#include <stack>
#include<vector>


//Stock price difference with reference ti recent highest stock
using namespace std;

int main() {

	vector<int> v;
	stack<int> s;
	int n; cin >> n;

	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int k;
	for(auto price : v) {
		if(s.empty()) {
			s.push(price);
			continue;
		} else if(price < s.top()) {
			k = s.top();
			s.push(price);
		} else if(price >= s.top()) {
			while(price >= s.top()) {
				s.pop();
			}
			s.push(price);
		}
		cout << abs(price-k) <<endl;
	}

	return 0;
}
