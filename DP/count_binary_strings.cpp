#include <iostream> 
using namespace std; 

#define int long long 
int countStrings(int n) 
{ 
    int a[n], b[n]; 
    a[0] = b[0] = 1; 
    for (int i = 1; i < n; i++) 
    { 
        a[i] = a[i-1] + b[i-1]; 
        b[i] = a[i-1]; 
    } 
    return a[n-1] + b[n-1]; 
} 

void solve(){
    int n;
    cin>>n;
    cout<<countStrings(n)<<endl;
}

signed main() 
{ 
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0; 
}
