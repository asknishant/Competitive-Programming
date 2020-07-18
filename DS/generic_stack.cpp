#include<iostream>
#include<vector>
using namespace std;

//Implementation of stack using vector

template<typename T, typename U>
class Stack {
	vector<T> t;
	vector<U> u;
	public:
		void push(T x) {
			t.push_back(x);
		}
		bool empty() {
			return t.size() == 0;
		}
		void pop() {
			if(!empty())
				t.pop_back();
		}
		T top() {
			return t[t.size()-1];
		}
};
int main() {

	Stack<int,char> s;
	s.push(20);
	s.push(10);
	s.push(40);
	s.push('X');

	cout << s.top();

	return 0;
}
