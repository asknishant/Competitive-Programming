https://leetcode.com/problems/increasing-triplet-subsequence/submissions/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        vector<int> dp;
    
        dp.push_back(nums[0]);
        for(int i = 0; i < nums.size(); i++) {
            int idx = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
            if(idx == dp.size()) {
                dp.push_back(nums[i]);
            } else {
                dp[idx] = nums[i];
            }
        }
        return dp.size() >= 3;
    }
};
