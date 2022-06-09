#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,vector<string>> g;
int vis[10001] = {0};

int mod = 1e7+9;


int solve(vector<int> &v) {
    int n = v.size();

    pair<int,int> ar[n];
    for(int i = 0; i < n; i++) {
        ar[i].first = v[i];
        ar[i].second = i;
    }
    sort(ar,ar+n);
    
    vector<int> vis(n,false);
    int ans = 0;
    for(int i = 0; i < n; i++) {

        // If old position is equal to the new position or it is already at right place then continue
        int old_position = ar[i].second;
        if(vis[i] or old_position == i) continue;

        int node = i;
        int edges = 0;
        while(!vis[node]) {
            vis[node] = true;
            node = ar[node].second;
            edges += 1;
        }
       // cout << edges;
        ans += (edges -1);
    }
    return ans;
}
int main() {   
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif
    
    vector<int> v = {5,4,3,2,1};

    int p = solve(v);
    cout << p;
    return 0;   
}

