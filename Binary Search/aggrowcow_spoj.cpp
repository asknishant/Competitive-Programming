#include <bits/stdc++.h>
#define ll long long
#define Fastio  ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;

bool chk(ll arr[],ll n,ll distance,ll c){
    int cows=1; ll last=arr[0];
    for(int i=1;i<n;i++){
        if((arr[i]-last)>=distance){
            cows++;
            if(cows==c){
                return true;
            }
            last=arr[i];
        }
    }
    return false;
}
int main(void){
    Fastio;
    int test;   cin>>test;
    ll n,c;
    while(test--){
        cin>>n>>c;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        ll lo=0;
        ll hi=(arr[n]-arr[0]);
        ll mid;
        ll pos=0;
        while(hi>=lo){

            mid=lo+(hi-lo)/2;

            if(chk(arr,n,mid,c)){
                lo=mid+1;
                pos=mid;
            }else{
                hi=mid-1;
            }
        }
        cout<<pos<<endl;
    }

    return 0;
}