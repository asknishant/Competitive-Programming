//https://www.youtube.com/watch?v=X7SrnbgqHHs&t=3660s

//Ladder or stairs problem using DP.
//Q.Given a stairs find total number of ways to reach a paticular level when maximum jumps you can take is k.

#include <bits/stdc++.h>
using namespace std;

//for k = 3.Using Recursion willl give O(3^n).
int ways(int n) {
  if(n == 0)  return 1;
  else if(n < 0) return 0;
  else return ways(n-1) + ways(n-2) + ways(n-3);
}

//Using DP top down approach(Recursion + memoization)
int topBottom(int n, int dp[]) {
  if(n == 0) {
    dp[n] = 1;
    return  dp[n];
  }else if(n < 0) {
    return 0;
  } else if(dp[n] != -1) {
    return dp[n];
  }
  dp[n] = topBottom(n-1, dp) + topBottom(n-2, dp) + topBottom(n-3, dp);
  return dp[n];
  
}

//Using bottom up approach for k = 3.
int bottomUp(int n) {
  int* dp = new int[n];
  dp[0] = 1;

  if(n < 0){
    dp[n] = 0;
    return dp[n];
  } 
  
  for(int i=1;i<=n;i++) {
    dp[i] = 0;
   for(int j=1;j<=3;j++){
     if(i >= j)
     dp[i] += dp[i-j];
   }
  }
  return dp[n];
}  


//for a random k.(Recursion)
int ways2(int n, int k) {
  if(n == 0) {
    return 1;
  }
  if(n < 0) return 0;

  int ans = 0;
  for(int j=1;j<=k;j++) {
    ans += ways2(n-j,k);
  }
  return ans;
}


int main() {

  int n;  cin >> n;
  int dp[100];
  for(int i=0;i<100;i++) {
    dp[i] = -1;
  }
  cout << ways(n) << endl;
  cout << topBottom(n, dp) << endl;
  cout << bottomUp(n) << endl;
  cout << ways2(n, 3);
  return 0;
}
