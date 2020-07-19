#include <iostream>
#include <stack>
using namespace std;
void transfer(stack<int> &s1, stack<int> &s2, int n) {
	for(int j=0;j<n;j++) {
		s2.push(s1.top());
		s1.pop();
	}
}

void reverseStack(stack<int> &s1) {
	stack<int> s2;  //Helper Stack.
	int size = s1.size();

	for(int i=0;i<size;i++) {
		//pick the element ar top.
		int x = s1.top();
		s1.pop();
		//transfer size-1-i elements from s1 to s2.
		transfer(s1, s2, size-i-1);
		s1.push(x);
		//transfer size-1-i elements from s2 to s1.
		transfer(s2,s1,size-i-1);
	}
}

int main() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	reverseStack(s);

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return  0;
}
