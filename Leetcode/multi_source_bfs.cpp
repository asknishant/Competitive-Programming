//https://leetcode.com/problems/as-far-from-land-as-possible/submissions/1
class Solution {
public:
    
    bool isValid(int i, int j, int n, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >=n || grid[i][j] == 1) return false;
        return true;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
         queue<pair<int,int>> qp;
         vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
         int n = grid.size();
         int on = 0;
         int zr = 0;
         for(int i = 0; i < n ; i++){
             for(int j = 0; j < n; j++){
                 if(grid[i][j] == 1) {on++; qp.push({i,j});}
                 else zr++;
             }
         }
          // edge cases
          if(on == n * n || on == 0) return -1;
         
          int ans = 0;
        
         while(!qp.empty()){
             ans++;
             int sz = qp.size();
             for(int k = 0; k < sz; k++){
                  pair<int, int> p = qp.front();
                  qp.pop();
                  int x = p.first;
                  int y = p.second;
                  for(auto dir : directions){
                      int xx = x + dir.first; int yy = y + dir.second;
                      if(isValid(xx, yy, n, grid)){
                              zr--; qp.push({xx,yy}); grid[xx][yy] = 1;
                         }
                  }
             }
               if(zr == 0) break;
         }
           return ans;
    }
};
