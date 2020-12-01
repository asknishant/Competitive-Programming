#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int lcs(string s1,string s2) {

    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int> > dp(n1+1,vector<int>(n2+1,0));

    for(int i=1;i<=n1;i++) {
        for(int j=1;j<=n2;j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            if(s1[i-1] != s2[j-1]){
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    for(int i=0;i<=n1;i++) {
        for(int j=0;j<=n2;j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n1][n2];
}

int main() {

    inlineDebug();

    string s1,s2;
    cin >> s1 >> s2;

    cout << lcs(s1,s2);
}
