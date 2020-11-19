//Wines problem-Given an arrayof prices of wines.Find the maximum profit by selling bottles where selling is allowed from either end in each year.
//Good problem in dp.

#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int profit(int i,int j,int y,int wines[],int dp[][100]) {

    if(i > j) {
        return 0;
    }

    if(dp[i][j] != 0) {
        return dp[i][j];
    }

    int op1 = y*wines[i] + profit(i+1,j,y+1,wines,dp);
    int op2 = y*wines[j] + profit(i,j-1,y+1,wines,dp);

    return dp[i][j] = max(op1,op2);
}

int main() {
    inlineDebug();

    int wines[] = {2,3,5};
    int n = sizeof(wines)/sizeof(int);

    int dp[100][100];    

    int i = 0;
    int j = n-1;
    int y = 1;


    cout << profit(i,j,y,wines,dp) << endl;

    //Just for reference see the dp array and tree formed through it.
    /*
        0,1,2 are indices.
        
        0-2
        /  \
      0-1  1-2
      / \   / \       
     00 11 11 22     


    */
    for(int k=0;k<3;k++) {
        for(int l=0;l<3;l++)
                cout << dp[k][l] << " ";
            cout << endl;
    }
}
