/*
  Xenia and Ringroad
  Codeforces/339B
  Accepted
  by->asknishant.39
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n,m;  cin>>n>>m;
  long long sum=0;
  int prev=1;
  while(m--){
    int k;  cin>>k;
   if(prev<k)
    sum+=(k-prev);
    else if(prev>k)
      sum+=(n-prev+k);

    prev=k;
  }
  cout<<sum;
  return 0;
}
