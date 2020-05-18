//T-primes Codeforces
//Codeforces Round #142 (Div. 2)
//by->asknishant.39

#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MAX = 1e6+(1e6/2)+3;
int primeSieve[MAX];
int main(void){
  //making a sieve.
  primeSieve[0]=-1;
  primeSieve[1]=-1;
  for(ll i=2;i*i<MAX;i++){
    if(!primeSieve[i])
      for(ll j=i+i;j<MAX;j+=i)
        if(primeSieve[j]<i)
          primeSieve[j]=i;
  }
  //A squared prime will be a t-prime.Or a prime when squared becomes a t-prime.

  int n;  cin>>n;
  while(n--){
    ll val;
    cin>>val;
    //binary searching of the prime whose square is val.
    		ll l=0, r=MAX, mid=l+(r-l)/2;
		while (r-l!=1)
		{
			if ((mid*mid)>val)
				r=mid;
			else
				l=mid;
			mid=l+(r-l)/2;		
		}
   		if (r*r == val and primeSieve[r]==0)
			cout << "YES" << endl;
		else if (l*l == val and primeSieve[l]==0)
			cout << "YES" << endl;
		else	
			cout << "NO" << endl;				
    
  }
  return 0;
}
