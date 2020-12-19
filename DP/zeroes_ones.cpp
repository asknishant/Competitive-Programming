//Leetcode ones and zeroes - smae as 0-1 knapsack.

class Solution {
public:
    
    int large(vector<string> &strs,int m,int n,int idx) {
        if(idx >= strs.size()) {
            return 0;
        }
        
        int no_ones = 0;
        int no_zeroes = 0;
        string str = strs[idx];
        for(int i=0;i<str.length();i++) {
            if(str[i] == '1') {
                no_ones++;
            } else {
                no_zeroes++;
            }
        }
        
        int op1 = 0;
        int op2 = 0;
        int op3 = 0;
        if(no_zeroes <= m and no_ones <= n) {
            op1 = 1+large(strs,m-no_zeroes,n-no_ones,idx+1);
            op2 = large(strs,m,n,idx+1);
        }
        op3 = large(strs,m,n,idx+1);
        
        return max(op1,max(op2,op3));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
       return large(strs,m,n,0);
    }
};
