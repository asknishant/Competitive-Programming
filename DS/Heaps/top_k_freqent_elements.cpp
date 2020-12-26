class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> mp;
        set<int> ans;
        
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        
        priority_queue<int> pq;
        
        
        for(auto x : mp) {
            pq.push(x.second);
        }
        
        for(int i=0;i<k;i++) {
            int ele = pq.top();
            pq.pop();
            for(auto x:mp) {
                if(x.second == ele) {
                    ans.insert(x.first);
                }
            }
            if(ans.size() == k) {
                break;
            }
        }
        
        vector<int> v;
        for(auto x:ans) {
            v.push_back(x);
        }
        return v;
    }
};
