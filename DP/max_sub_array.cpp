#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int maxSum(int arr[],int n) {

    int dp[100] = {0};
    int max_till_now = 0;
  
    dp[0] = (arr[0] < 0) ? 0 : arr[0];    //If first element is -ve then we wiil not consider it we will start from zero.

    for(int i=1;i<n;i++) {

        dp[i] = dp[i-1] + arr[i];
        if(dp[i] < 0) {
            dp[i] = 0;
        }
       
        max_till_now = max(dp[i],max_till_now);
    }
    return max_till_now;
}

int main() {

    inlineDebug();

    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(arr)/sizeof(int);

    cout << maxSum(arr,n);
    return 0;
}
