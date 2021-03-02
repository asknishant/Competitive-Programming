
//https://leetcode.com/problems/closest-dessert-cost/

class Solution {
public:
    
    void solve(int cost,int i,vector<int>& toppingCosts,int target,int &best) {
        //Base case;
        //1. If the abs(cost - target < abs(bes - target)) -> best = cost.
        //2. If abs(cost - target) == abs(best - target) -> best = min(best,cost).
        
        if(cost >= target or i >= toppingCosts.size()) {
            if(abs(cost-target) < abs(best-target)) {
                best = cost;
            }
        } else {
            for(int j=0;j<=2;j++) {
                solve(cost+j*toppingCosts[i],i+1,toppingCosts,target,best);
            }
        }
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int best = INT_MAX;
        for(int i=0;i<baseCosts.size();i++) {
            solve(baseCosts[i], 0, toppingCosts, target, best);
        }
        return best;
    }
};
