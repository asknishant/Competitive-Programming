#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int minCoins(int dp[],int coins[],int n,int deno) {

    //Base Case
    if(n == 0) {
        return 0;
    }

    //Rec case
    int ans = INT_MAX;
    int subprob;
    for(int i=0;i<deno;i++) {
        if(n-coins[i] >= 0)
            subprob = minCoins(dp,coins,n-coins[i],deno) + 1;
        ans = min(subprob,ans);
    }

    dp[n] = ans;
    return dp[n];
}

int bottomUP(int n,int deno,int coins[]) {

   int dp[100] = {0};

   for(int i=1;i<=n;i++) {

        dp[i] = INT_MAX;
        for(int j=0;j<deno;j++) {
           
            if(i-coins[j] >= 0) {
                int subprob = dp[i-coins[j]];
                dp[i] = min(dp[i],subprob+1); 
            }
        }
   }
   return dp[n];
}
int main() {
    inlineDebug();

    int dp[100] = {0};
    int coins[3] = {1,7,10};
      
    int mC = minCoins(dp,coins,15,3);
    cout << mC << endl;

    cout << bottomUP(15,3,coins);

}
