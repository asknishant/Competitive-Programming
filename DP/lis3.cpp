//This is the binary search appraoch - O(NlogN)


#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int lis(int *arr,int n) {

    int dp[n+1];

    dp[0] = INT_MIN;
    for(int i=1;i<=n;i++) {
        dp[i] = INT_MAX;
    }

    for(int i=0;i<n;i++) {
        // for(int j=0;j<n;j++) {
        //     if(arr[i] > dp[j] and arr[i] < dp[j+1]) {
        //         dp[j+1] = arr[i];
        //     }
        // }


        //This gives the upper bound of dp[i].We are using binary search as dp array is alwys increasing.
        int upr_index = upper_bound(dp,dp + n + 1,arr[i]) - dp;
        if(dp[upr_index] > arr[i] and dp[upr_index - 1] < arr[i]) {
            dp[upr_index] = arr[i];
        }
    }

     for(int i=1;i<=n;i++) {
        cout << dp[i] << " ";
    }

    int lis = 0;
    for(int i=1;i<=n;i++) {
        if(dp[i] != INT_MAX)    lis = i;
    }
    return lis;
}
int main() {

    inlineDebug();

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    cout << lis(arr,n);
    return 0;
}
