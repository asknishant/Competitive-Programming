//This also gives O(N^2)

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
        for(int j=0;j<n;j++) {
            if(arr[i] > dp[j] and arr[i] < dp[j+1]) {
                dp[j+1] = arr[i];
            }
        }
    }

     for(int i=1;i<=n;i++) {
        cout << dp[i] << " ";
    }

    int lis = 0;
    for(int i=1;i<n;i++) {
        if(dp[i] != INT_MAX)    lis = i;
    }
    return lis;
}
int main() {

    inlineDebug();

    int arr[] = {1,5,2,3,4,9,6,10};
    int n = sizeof(arr)/sizeof(int);

    cout << lis(arr,n);
    return 0;
}
