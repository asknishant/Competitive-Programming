
//Sum of two numbers using two pointers.
//Given an array A check whether the sum of two numbers equal to x is present or not inside the array.
//This gives a complexity of O(n^3).Though we can find a better soln with O(n^2logn).(https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/?ref=lbp)

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int arr[] = {2,4,-1,3,-4,0,3};
	
	int x=5;
	int i=0;
	int j=6;
	sort(arr,arr+7);
	while(i<j){
		if((arr[i]+arr[j]) > x) {
			j--;
		}else if((arr[i]+arr[j]) < x){
			i++;
		}else {
			cout<< i << j;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}