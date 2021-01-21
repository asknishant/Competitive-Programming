class Solution {
public:
    
    vector<int>ans;
    
    void dfs(TreeNode *root,int k){
        if(!root)return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        dfs(root->left,k-1);
        dfs(root->right,k-1);
    }
    
    int solve(TreeNode*root,TreeNode* t,int k){
        if(!root)return -1;
        
        if(root==t){
            dfs(root,k);
            return 0;
        }
        
        int l=solve(root->left,t,k);
        if(l!=-1){
            if(k==l+1){
                ans.push_back(root->val);
            }else{
                dfs(root->right,k-2-l);
            }
            return l+1;
        }
        
        int r=solve(root->right,t,k);
        if(r!=-1){
            if(k==r+1){
                ans.push_back(root->val);
            }else{
                dfs(root->left,k-2-r);
            }
            return r+1;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        solve(root,target,k);
        return ans;
    }
};
