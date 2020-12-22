//https://leetcode.com/problems/subarray-sums-divisible-by-k/submissions/

class Solution {
public:
    
    
    int subarraysDivByK(vector<int>& A, int k) {
        
        
        int sum = 0;
        int ans = 0;
        map<int,int> mp;
        mp.insert({0,1});
        for(int i=0;i<A.size();i++) {
            sum+=A[i];
            int r = (sum)%k;
            //In case of negative remaider take add k.
            if(r<0) r += k;
            if(mp.find(r) != mp.end()) {
                ans+=mp[r];
            }
            mp[r]++;
        }
        
        return ans;
    }
};
