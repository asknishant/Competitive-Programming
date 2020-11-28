//Longest increasing subsequence..
//There are four ways to solve this
///This is method 1 - O(N^2)


#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int lis(int *arr,int n) {


    int dp[n+1] = {1};
    int ans = INT_MIN;
    int currMax = INT_MIN;
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {

            // for lis j < i and arr[j] < arr[i]
            if(arr[j] < arr[i]) {
             dp[i] = max(dp[i],dp[j] + 1);  //If the if condition satisfies then claculate the max.
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout << dp[i] << " ";
    }
    return dp[n];
}
int main() {

    inlineDebug();

    int arr[] = {1,5,2,3,4,9,6,10};
    int n = sizeof(arr)/sizeof(int);

    cout << lis(arr,n);
    return 0;
}
