//This is slight variation of matrix chain multiplication

#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

long long arr[1000];
long long dp[1000][1000];

long long sum(int s,int e) {
    long long ans = 0 ;
    for(int i=s;i<=e;i++) {
        ans += arr[i];
        ans %= 100;
    }   
    return ans;
}

long long solveMixtures(int i, int j) {


    //Base case
    if(i>=j) {
        return 0;
    }

    //If answer is already there.
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    //We have to break our array ar every k.
    dp[i][j] = INT_MAX;
    for(int k=i;k<=j;k++) {

        dp[i][j] = min(dp[i][j], solveMixtures(i,k) + solveMixtures(k+1,j) + sum(i,k) * sum(k+1,j));
    }
    return dp[i][j];
}

int main() {

    inlineDebug();
    int n;
    while(scanf("%d",&n) != EOF) {

        for(int i=0;i<n;i++)    cin >> arr[i];

        for(int i=0;i<1000;i++) {
            for (int j = 0; j < 1000; j++)
            {
                dp[i][j] = -1;           
            }
        }

        cout << solveMixtures(0,n-1) << endl;
    }
    return 0;
}
