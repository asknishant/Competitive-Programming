/*
 Codeforces 508B
 Anton and currency you all know
 status-Accepted
 by-asknishant.39
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int* x,int* y){
  int temp=*x;
  *x=*y;
  *y=temp;
}
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin>>s;
  int l=(s.length()-1);
  int k=-1;
  int temp=0;
  for(int i=0;i<s.length();i++){
    if((int)(s[i]-48)%2==0){
      if(s[l]>s[i]){
        k=i;
        break;
      }
      k=i;
    }
  }
  if(k==-1){
    cout<<-1;
    return 0;
  }
  temp=s[k];
  s[k]=s[l];
  s[l]=temp;

  for(int i=0;i<s.length();i++){
    cout<<(s[i]-48);
  }
  return 0;
}
