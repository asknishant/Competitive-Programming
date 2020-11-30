#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


int td_dp(int i,int j,int dp[][100],int arr[]) {

    //Base case
    if(i>j) return 0;

    if(dp[i][j] != 0) {
        return dp[i][j];
    }
    //Rec case

    int op1 = arr[i] + min(td_dp(i+2,j,dp,arr),td_dp(i+1,j-1,dp,arr));
    int op2 = arr[j] + min(td_dp(i,j-2,dp,arr),td_dp(i+1,j-1,dp,arr));            
    return dp[i][j] = max(op1,op2);

}
int main() {

    inlineDebug();

     int arr[] = { 20, 30, 2, 2, 2, 10 }; 
    int n = sizeof(arr)/sizeof(int);
    int dp[100][100] = {0};

   
    cout << td_dp(0,n-1,dp,arr)<<endl;

     for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
