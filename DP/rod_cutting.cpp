#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


int rodCut(int arr[],int len) {

    //Base case
    if(len <= 0) {
        return 0;
    }

    //Recursive case
    int ans = INT_MIN;
    for(int i=0;i<len;i++) {
        int profit = arr[i] + rodCut(arr,len-(i+1));
        ans = max(profit,ans);
    }
    return ans;
}

int rodCutDp(int prices[],int len) {

    //Base case
    int dp[100] = {0};
    
    for(int i=1;i<=len;i++) {
      int ans = INT_MIN;
      for(int j=0;j<i;j++) {
        int curr_ans = prices[j] + dp[i-(j+1)];
        ans = max(ans,curr_ans);
      }
      dp[i] = ans;
    }
    return dp[len];
}
int main() {

    inlineDebug();


    int prices[] = {1,5,8,9,10,17,17,20};

    int len = sizeof(prices)/sizeof(int);
    cout << rodCutDp(prices,len) << endl;


    return 0;
}
