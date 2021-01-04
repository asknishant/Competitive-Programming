// Q :- https://leetcode.com/problems/make-sum-divisible-by-p/submissions/

//soln :- https://www.krammerliu.com/blog/leetcode-1590-make-sum-divisible-by-p/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int sum = 0;
        int ans = INT_MAX;
        int n = nums.size();
        vector<int> pre(n);
        
        //We are storing remainder upto each i.At last we will get remainder of whole array.
        for(int i=0;i<n;i++) {
            sum += nums[i];
            sum %= p;
            pre[i] = (sum);
        }
         if(pre.back()%p == 0)   return 0;
        int target = pre.back()%p;//We have to check where (target-pre[i])%p has already occured.
       
        unordered_map<int,int> mp;
        mp.insert({0,-1});
        
        for(int i=0;i<n;i++) {
            int x = pre[i]- target;
            if(x<0) x += p;
            if(mp.count(x) and (i != n-1 or mp[x] != -1)) {
                ans = min(ans,i-mp[x]);
            }
            mp[pre[i]] = i;
        }
         return ans == INT_MAX ? -1 : ans;
    }
};
