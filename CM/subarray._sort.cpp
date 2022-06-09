#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,vector<string>> g;
int vis[10001] = {0};

int mod = 1e7+9;


bool outOforfer(int i, vector<int> &v) {
    int x = v[i];

    if(i == 0) {
        return x > v[i+1];
    }
    if(i == v.size() - 1) {
        return x < v[i-1];
    }

    return x < v[i-1] or x > v[i+1]; 
}
pair<int,int> solve(vector<int> &v) {
    int smallest = INT_MAX;
    int largest = INT_MIN;

    int n = v.size();
    for(int i = 0; i < n; i++) {
        if(outOforfer(i,v)) {
            smallest = min(smallest,v[i]);
            largest = max(largest,v[i]);
        }
    }

    if(smallest == INT_MAX) {
        return {-1,-1};
    }

    int left = 0;
    while(v[left] <= smallest) {
        left++;
    }
    int right = n-1;
    while(v[right] >= largest) {
        right--;
    }

    return {left,right};
}
int main() {   
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif
    
    vector<int> v = {1,2,3,4,5,8,6,7,9,10,11};

    auto p = solve(v);
    cout << p.first << " " << p.second;
    
    return 0;   
}

