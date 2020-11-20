#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int ways_stairsTD(int n,int k,int dp[]) {
    if(n==0) {
        return 1;
    }

    if(dp[n] != 0) {
        return dp[n];
    }

    for(int i=1;i<=k;i++) {
        if((n-i) >= 0)
            dp[n] += ways_stairs(n-i,k,dp);
    }

    return dp[n];
}

int ways_stairsBU(int n,int k) {
    int dp[100] = {0};

    dp[0] = 1;  //Base case
    
    for(int i=0;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            if(i-j >= 0) {
                dp[i] += dp[i-j];
            }
        }
    }
    return dp[n];
}

int main() {

    inlineDebug();

    int dp[100] = {0};
    cout << ways_stairsBU(4,3);

    return 0;
}
