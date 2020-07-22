#include <bits/stdc++.h>
using namespace std;

int main() {

	queue<char> q;
	char freq[27] = {0};
	char ch;
	cin >> ch;
	while(ch!='.') {
		q.push(ch);
		freq[ch-'a']++;

		while(!q.empty()) {
			int ind = q.front() - 'a';
			if(freq[ind] > 1) {
				q.pop();
			}else {
				cout << q.front() << " ";
				break;
			}
		}
		if(q.empty()) {
			cout << -1 << " ";
		}
		cin >> ch;
	}

	return 0;
}
