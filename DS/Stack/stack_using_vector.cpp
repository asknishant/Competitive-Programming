#include<iostream>
#include<vector>
using namespace std;

//Implementation of stack using vector

class Stack {
	vector<int> v;

	public:
		void push(int x) {
			v.push_back(x);
		}
		bool empty() {
			return v.size() == 0;
		}
		void pop() {
			if(!empty())
				v.pop_back();
		}
		int top() {
			return v[v.size()-1];
		}
};
int main() {

	Stack s;
	s.push(20);
	s.push(10);
	s.push(40);

	cout << s.top();

	return 0;
}
