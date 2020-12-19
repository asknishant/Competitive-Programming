class Solution {
public:
    
    int cuts(string s) {
             int n = s.length();
        vector<vector<bool> > dp(n+1,vector<bool>(n+1));
        vector<string> res;

        for(int g = 0; g < s.size(); g++) {
            for(int i=0,j=g;j<dp.size();i++,j++) {
                if(g==0) {
                    dp[i][j] = true;
                    //res.push_back(s.substr(i,g+1));
                } else if(g==1) {
                     dp[i][j] = s[i] == s[j];
                } else {
                    if(dp[i+1][j-1] == true and s[i] == s[j]) {
                         // res.push_back(s.substr(i,g+1));
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                }

            }
        }



        // for(int g=0;g<dp.size();g++) {
        //     for(int i=0,j=g;j<s.length();j++,i++) {
        //         if(!dp[i][j]) {
        //             //res.push_back(s.substr(g,j+1));
        //         }
        //     }
        // }

        vector<vector<int> > ans(n+1,vector<int>(n+1));


        // for(int g=0;g<s.size();g++) {
        //     for(int i=0,j=g;j<dp.size();i++,j++) {
        //         if(g==0) {
        //             ans[i][j] = 0;
        //         } else if(g==1){
        //             if(s[i] == s[j]) {
        //                 ans[i][j] = 0;
        //             } else {
        //                 ans[i][j] = 1;
        //             }
        //         } else {
        //             if(dp[i][j]) {
        //                 ans[i][j] = 0;
        //             } else {
        //                  int min = INT_MAX;
        //                 for(int k=i;k<j;k++) {
        //                     int left = ans[i][k];
        //                     int right = ans[k+1][j];
        //                     if(left+right+1 < min) {
        //                         min = left+right+1;
        //                     }
        //                 }
        //                 ans[i][j]=min;
        //             }  
        //         }
        //     }
        // }
        
        vector<int> strg(s.length(),0);
       for(int j=1;j<s.length();j++) {
           
           if(dp[0][j]) {
               strg[j] = 0;
           } else {
                int min = INT_MAX;
               for(int i=j;i>=1;i--) {
                   if(dp[i][j]) {
                       if(strg[i-1] < min) {
                           min = strg[i-1];
                       }
                   }
                   strg[j] = min + 1;
               }
            }
       }
       //return ans[0][s.length()-1];
        return strg[s.length()-1];
    }
    int minCut(string s) {
        return cuts(s);
    }
};
