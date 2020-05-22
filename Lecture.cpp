/*
Codeforces-499B
Lectures
Status-Accepted
by-asknishant.39
*/

#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  map<string,string> mp;
  int n,m;  cin>>n>>m;
  string a,b;
  while(m--){
    cin>>a>>b;
    mp[a]=b;
  }
  while(n--){
    cin>>a;
    b=mp[a];
    
    if(b.length()<a.length()){
      cout<<b<<" ";
    }else{
      cout<<a<<" ";
    }
  }
  return 0;
}
