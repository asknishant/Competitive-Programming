//Maxiimum sub array sum using Cummulative sum array o(n^2)

#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[100];
  int n;  cin >> n; 
  int cummulativeSum[n] = {0};

  cin >> arr[0];
  cummulativeSum[0] = arr[0];
  for(int i=1;i<n;i++) {
    cin >> arr[i];
    cummulativeSum[i] = cummulativeSum[i-1] + arr[i];
  }
  
  int left = -1;
  int right = -1;
  int currSum = 0;
  int maxSum = 0;

  for(int i=0;i<n;i++) {
    for(int j=i;j<n;j++) {
      currSum = cummulativeSum[j] - cummulativeSum[i-1];
      if(currSum > maxSum) {
        maxSum = currSum;
        left = i;
        right = j;
      }
    }
  }

  cout << "maximum Sum is " << maxSum;
  return 0;
}
