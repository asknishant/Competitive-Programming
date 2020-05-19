/*
 Random Teams
 Codeforces 478B
 Status-Accepted
 by->asknishant.39
*/

#include <iostream>
using namespace std;


int main(void){

  long long n,m;  cin>>n>>m;
  long long min,max;
  long long x=n-(m-1);
  max=(x*(x-1))/2;
  long long a=n%m;
  long long b=(m-a);
  long long y=n/m;
  min=b*(y*(y-1))/2+a*(y*(y+1))/2;

  cout<<min<<" "<<max;
  return 0;
}
