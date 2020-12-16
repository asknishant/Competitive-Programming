//Minimum cost for tickets.

class Solution {
public:
    
    int calcLb(vector<int> &days,vector<int> &costs,int inc,int date) {
        
        auto it = lower_bound(days.begin(),days.end(),date+inc);
        return it - days.begin();
    }
    int helper(vector<int> &days,vector<int> &costs,int day,vector<int> &dp) {
        
        //Base cases
        if(day == days.size()) {
            return 0;
        }
        
        //If cost for a particular date is already calcuated 
        if(dp[day] != -1) {
            //day is index of days vector
            return dp[day];
        }
        
        int date = days[day];
        
        int lb1 = calcLb(days,costs,1,date);
        int onedayPass = helper(days,costs,lb1,dp) + costs[0];
        int lb7 = calcLb(days,costs,7,date);
        int sevendayPass = helper(days,costs,lb7,dp) + costs[1];
        int lb30 = calcLb(days,costs,30,date);
        int thirtydayPass = helper(days,costs,lb30,dp) + costs[2];
        
        return dp[day] = min(onedayPass,min(sevendayPass,thirtydayPass));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return helper(days,costs,0,dp);
    }
};
