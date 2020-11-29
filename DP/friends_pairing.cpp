#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


int ways(int n,int dp[]) {

    if(n <= 1) {
        return 1;
    }

    if(dp[n] != 0) {
        return dp[n];
    }

    return dp[n] =  ways(n-1,dp) + (n-1)*ways(n-2,dp);
}


int main() {

    inlineDebug();
    int n;  cin >> n;
    int dp[100] = {0};

    for(int i=0;i<n;i++)    cout << dp[i];
    cout << ways(n,dp);
    return 0;
}
