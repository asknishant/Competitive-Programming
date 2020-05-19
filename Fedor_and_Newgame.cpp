/*
Fedor and Newgame
Codeforces 467/B
Accepted

by asknishant.39
*/

#include <bits/stdc++.h>
using namespace std;


int main(void){
  int n,m,k;  cin>>n>>m>>k;
  int a[m+1];
  for(int i=0;i<=m;i++){
    cin>>a[i];
  }
  //Fedor is (m+1)th guy i.e its position will be at m.
  //Creating an array to store bits.
  int fedor[n]; 
  int player[n];
  int m_copy=m;
  int match=0;
  int j=0;
  int f=a[m];
  int n1=n;
  int n2=n;
  while(n1--){
    fedor[j]=(f%2);
    f/=2;
    j++;
  }
// for(int i=0;i<n;i++)
//   cout<<fedor[i];
 for(int d=0;d<m;d++){
    int p=a[d];
    int l=0;
    n2=n;
    while(n2--){
      player[l]=(p%2);
      p/=2;
      l++;
    }
   
    int check=0;
    for(int i=0;i<n;i++){
      if(fedor[i]!=player[i])
        check++;
    }
    if(check<=k)
      match++;
  }
  std::cout<<match;
  return 0;
}
