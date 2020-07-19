#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	stack<char> s;
	
	string str;
	cin >> str;

	for(int i=0;i<str.length();i++) {
		char ch = str[i];
		if(ch == '(') {
			s.push(ch);
		} else if(ch == ')' or s.top()!='('){	
			 if(s.top() == '(') {
				cout << "Not Balanced";
				return 0;
			}
			s.pop();
		}
	}
	for(int i=0;i<str.length();i++)	cout << str[i];
	if(s.empty()) cout << "Balanced";
	else cout << "Not Balanced";
	return 0;
}
