/*
Jzzhu and Sequences
Codeforces 450B
status-Accepted
by-asknishant
*/

#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(void){
    
    ll x,y,n;
    cin>>x>>y>>n;
    ll mod=n%6;
    ll ans;
    if(mod==0)
        ans=x-y;
    else if(mod==1)
        ans=x;
    else if(mod==2)
        ans=y;
    else if(mod==3)
        ans=y-x;
    else if(mod==4)
        ans=-x;
    else if(mod==5)
        ans=-y;
        
    ans%=MOD;
    if(ans<0)
        ans+=MOD;
    cout<<ans;
    return 0;
}
