    int helper(TreeNode* root,int parent)
    {
        if(!root||root->val!=parent)return 0;
            return max(helper(root->left,parent),helper(root->right,parent))+1;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        int childmax=max(longestUnivaluePath(root->left),longestUnivaluePath(root->right));
        return max(childmax,helper(root->left,root->val)+helper(root->right,root->val));
    }