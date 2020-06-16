    int ans=0;
    void solve(TreeNode* root,int m)
    {
        if(!root)return;
        if(root->val>=m)ans++;
        solve(root->left,max(root->val,m));
        solve(root->right,max(root->val,m));
    }
    int goodNodes(TreeNode* root) {
        if(!root)return ans;
        solve(root,INT_MIN);
        return ans;
    }
