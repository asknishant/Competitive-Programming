//CB-> Use of comparators for sorting.

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.second < b.second; 
}
int main() {

	int test;	cin >> test;

	while(test--) {
		int N;	cin >> N;
		int m,n;
		pair<int,int> arr[N];

		for(int i=0;i<N;i++) {
			cin >> m >> n;
			arr[i] = make_pair(m, n);
		}

		sort(arr, arr+N, cmp);
// 		for(int i=0;i<N;i++) {
// 			cout << arr[i].first << " " << arr[i].second << endl;
// 		}
		int no_of_activities = 1;
		int pair_no = 0;
		for(int i=1;i<N;i++) {
			if(arr[pair_no].second <= arr[i].first) {
				no_of_activities++;
				pair_no = i;
			}
		}
		cout << no_of_activities << endl;
	}

	return 0;
}
