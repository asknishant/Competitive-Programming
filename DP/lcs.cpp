#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


int lcs(string s1,string s2,int i,int j,vector<vector<int> > &dp) {

    if(i == s1.length() or j == s2.length()) {
        return 0;
    }

    if(s1[i] == s2[j]) {
        return dp[i][j] = 1 + lcs(s1,s2,i+1,j+1,dp);
    }

    int op1 = lcs(s1,s2,i+1,j,dp);
    int op2 = lcs(s1,s2,i,j+1,dp);

    return dp[i][j] = max(op1,op2);
}
int main() {

    inlineDebug();

    string s1,s2;
    cin >> s1 >> s2;

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int> > dp(n2,vector<int>(n1,-1));     //n1 X n2
    cout << lcs(s1,s2,0,0,dp);


    cout << endl;

    for(int i=0;i<dp.size();i++) {
        for(int j=0;j<dp[0].size();j++) {
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }    
    return 0;
}
