class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 2) {
            return s.length();
        }
        int len = s.length();
        unordered_set<char> st;
        int ans = 0;
        int l = 0;
        int i =0;
        while(i < s.size()) {
            
            if(st.find(s[i]) == st.end()) {
                ans = max(ans,i-l+1);
                st.insert(s[i]);
                i++;
            } else {
                st.erase(s[l]);
                l++;
                
            }
            
        }
      
        return ans;
    }
};

int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("dvdf");
  return 0;
}
