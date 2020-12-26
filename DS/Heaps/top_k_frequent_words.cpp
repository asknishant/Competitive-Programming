class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        
        unordered_map<string,int> mp;
        for(auto const &x: words) {
            mp[x]++;
        }
        
        //This is a min heap.To sort it with value we can use greater<pair<in,int>> 
        //but if values are equal then we willl sort it alphabetically.So use com function.
        auto comp = [&](const pair<string,int> a, const pair<string,int> b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        typedef priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(comp) > pqt;
        pqt pq(comp);
        
    
        for(auto it = mp.begin();it!=mp.end();it++) {
            pq.push({it->first,it->second});
            if(pq.size() > k) pq.pop();
        }
       vector<string> res;
        while(k--) res.push_back(pq.top().first), pq.pop();
        reverse(res.begin(), res.end());
        return res;     
        

    }
};
