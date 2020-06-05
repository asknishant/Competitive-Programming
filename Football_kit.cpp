/*
Codeforces 432B
Football kit
status-accepted
by - asknishant
*/

#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;  cin >> n;
    int kits_home[n],kits_away[n];
    int cnt[MAX] = {0};
    int home[n],away[n];
    
    for(int i=0;i<n;i++){
        cin >> kits_home[i];   
        cin >> kits_away[i];
        cnt[kits_home[i]] += 1;
    }
    for(int i=0;i<n;i++){
        home[i] = (n-1) + cnt[kits_away[i]];
        away[i] = (n-1) - cnt[kits_away[i]];
    }
    
    for(int i=0;i<n;i++){
        cout << home[i] << " " << away[i] <<"\n";
    }
    
    return 0;
}
