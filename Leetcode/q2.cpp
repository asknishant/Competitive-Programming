//https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/submissions/


class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        
        int left[boxes.size()];
        memset(left,0,boxes.size()*sizeof(int));
        int count = boxes[0] - '0';
        for(int i = 1; i < boxes.size(); i++) {
            left[i] = left[i-1] + count;
            count += boxes[i] - '0';
        }
        
        int right[boxes.size()];
        memset(right,0,boxes.size()*sizeof(int));
        count = boxes[boxes.size()-1] - '0';
        for(int j = boxes.size()-2; j >= 0; j--) {
            right[j] = right[j+1] + count;
            count += boxes[j] - '0';
        }
        
        
        for(int i = 0; i < boxes.size(); i++) {
            int res = left[i] + right[i];
            ans.push_back(res);
        }
        return ans;;
    }
};
