/*
Explanation:-https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal

Algorithm:-
1.We perfom a dfs(post oreder) on the tree.
2.We we simulatneously cache in our steps count 
3. We update the root value as |dfs(root->left)| + |dfs(root->right)|
4.We return root->val-1
*/
    int dfs(TreeNode* root,int &steps)
    {
        if(!root)return 0;
        int l=dfs(root->left,steps);
        steps+=abs(l);
        int r=dfs(root->right,steps);
        steps+=abs(r);
        root->val+=l+r;
        return root->val-1;
        
    }
    int distributeCoins(TreeNode* root) {
        if(!root)return 0;
        int steps=0;
        dfs(root,steps);
        return steps;
    }