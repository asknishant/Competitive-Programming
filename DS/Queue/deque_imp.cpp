//SPOJ arraysub
//Finding maximum element in a window of k.


#include "iostream"
#include <deque>

using namespace std;

int main() {

	int n;	cin >> n;
	int a[100000];
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	int k;	 cin >> k;

	deque<int> dq(k);
	//Processing first k elements.
	int i;
	for(i=0;i<k;i++) {
		while(!dq.empty() and a[i] >a[dq.back()]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for(;i<n;i++) {
		cout << a[dq.front()] << " ";

		//Removing all the indices which are less than current window range.
		while(!dq.empty() and (dq.front() <=(i-k))) {
			dq.pop_front();
		}
		//Removing all indices of elements which are less elements of current window.
		while(!dq.empty() and a[dq.back()] <= a[i]) {
			dq.pop_back();
		}
		//Add every ith index.
		dq.push_back(i);
	}

	//loop ends and last element was not printed so,
	cout << a[dq.front()] << endl;

	return 0;
}
