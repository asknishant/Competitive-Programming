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


//In this case we push all the coordinates(be it zero or one) to the queue and find which ones are visited. In previous case we saved this overhead and pushed only those coordinates
//which were valid(not have crossed boundary and were zero)
 
class Solution {
public:
    
    bool isValid(int i,int j,vector<vector<int>> &grid) {
        return i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size();
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int dist = 0;
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int on = 0, zr = 0;
        vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {on++,q.push({i,j});}
                else zr++;
            }
        }
        vector<vector<int> > seen(grid.size(),vector<int>(grid[0].size(),false));
        if(on == m*n or zr == 0) return -1;
        if(q.empty()) return -1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
            
                if(seen[x][y]) continue;
                seen[x][y] = true;
                if(grid[x][y] == 0) zr--;  
                    cout << x << " " << y << endl;
               // cout << grid[x][y] << " ";
                for(int i = 0; i < dirs.size(); i++) {
                    auto dir = dirs[i];
                    int xx = x + dir[0];
                    int yy = y + dir[1]; 
                    if(isValid(xx,yy,grid)) {
                        q.push({xx,yy});
                    }
                }
                
            }
            if(zr == 0) break;
            cout << endl;
            dist++;
        }
        return dist;
    }
};
