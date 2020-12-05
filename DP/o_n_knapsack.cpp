#include<bits/stdc++.h>
#define ll long long
using namespace std;


void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int main() {

    //inlineDebug();
    
    ll n,w;
    cin >> n >> w;

    ll values[n],weights[n];
    ll dp[w+1] = {0};

    for(int i=0;i<n;i++) {
        int x; cin >> x;
        weights[i] = x;
    }

    for(int i=0;i<n;i++) {
        int x; cin >> x;
        values[i] = x;
    }

    dp[0] = 0;
    for(ll currCap=0;currCap<=w;currCap++) {
        ll profit = 0;
        for(int j=0;j<n;j++) {
            ll value_of_currCap = 0;

            if(weights[j] <= currCap) {
                ll remCap = currCap - weights[j];
                value_of_currCap = dp[remCap] + values[j];
               profit = max(profit, value_of_currCap);
            }
        }
       dp[currCap] = profit;
    }

    cout << dp[w];
    
    //for(int i=0;i<w+1;i++)  cout << dp[i] << " ";
    return 0;   
}
