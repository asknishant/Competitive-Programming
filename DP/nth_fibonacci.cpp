//https://www.youtube.com/watch?v=X7SrnbgqHHs&t=3660s

#include <bits/stdc++.h>
using namespace std;

//Using DP --> Top Down approach(Recursion+memoization). O(n) complexity.
int fibDP(int n, int dp[]) {
  if(n == 0 || n == 1){
    dp[n] = n;
    return dp[n];
  }
  if(dp[n] != -1) {
    return dp[n];
  }
  else {
    dp[n] = fibDP(n-1, dp) + fibDP(n-2, dp);
    return dp[n];
  }
}


//Bottom up Approach
int bottomUp(int n) {
  // Here n is the size of the array.
  int* dp = new int[n];

  dp[0] = 0;
  dp[1] = 1;

  for(int i=2;i<=n;i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}

//Recursion -> This gives O(2^n) complexity. 
int fib(int n) {
  if(n == 0 || n == 1) {
    return n;
  }
  return fib(n-1) + fib(n-2);
}

int main(void) {

  int n;  cin >> n;
  int dp[1000];
  cout << fib(n) << endl;

  for(int i=0;i<1000;i++)
    dp[i] = -1;
  cout <<  fibDP(n, dp) << endl;
  cout << bottomUp(n);
  return 0;
}
