//Stairs problem 
#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//complexityO(NK)
int ways_stairs(int n,int k,int dp[]) {
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


//For sliding window - for all i <= k => dp[i] = 2*dp[i-1] and for all i>k dp[i] = 2*dp[i-1] - dp[i-k-1]; 
int sliding_window(int n,int k) {   //O(N)

    int dp[100] = {0};

    //Base cases.
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=k;i++) {
        dp[i]  = 2 * dp[i-1];
    }

    for(int i=k+1;i<=n;i++) {
        dp[i] = 2 * dp[i-1] - dp[i-k-1];
    }

    for(int i=0;i<=n;i++)    cout << dp[i] << " ";

    return dp[n];
}
int main() {

    inlineDebug();

    int dp[100] = {0};
    cout << sliding_window(6,3);

    return 0;
}
