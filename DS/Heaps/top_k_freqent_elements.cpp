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
};  //O(N*K)


//Solution 2 O(NlogK)


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        for(auto const x : nums) {
            mp[x]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto x : mp) {
            pq.push({x.second,x.first});
            while(pq.size() >k) {
                pq.pop();
            }
        }
        
        vector<int> ans;
        for(int i=0;i<k;i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
