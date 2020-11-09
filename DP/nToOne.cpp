//Find no of steps to convert N to 1.If N can perform N/2,N/3 and N-1.

#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int nToOneTop(int dp[],int n) {
    if(n == 1) return 0;

    if(dp[n] != -1) {
        return dp[n];
    }

    int op1,op2,op3;
    op1 = op2 = op3 = INT_MAX;
    if(n%2 == 0) {
        op1 = nToOneTop(dp,n/2);
    }
    if(n%3 == 0) {
        op2 = nToOneTop(dp,n/3);
    }  
    op3 = nToOneTop(dp,n-1);

    return dp[n] = min(min(op1,op2),op3) + 1;
}

int nToOneDown(int n) {
    int dp[100];
    memset(dp,0,100);

    dp[1] = 0;

    for(int i=2;i<=n;i++) {
        int op1,op2,op3;
        op1 = op2 = op3 = INT_MAX;
        if(i%3 == 0) {
            op1 = dp[i/3];
        }
        if(i%2 == 0) {
            op2 = dp[i/2];
        }
        op3 = dp[i-1];

        dp[i] = min(min(op1,op2),op3) + 1;
    }
   
    return dp[n];
}


int main() {
    inlineDebug();

    int dp[100];
    memset (dp,-1,100);

    int n;
    cin >> n;

    cout << nToOneTop(dp,n) << endl;

    cout << nToOneDown(n);

}
