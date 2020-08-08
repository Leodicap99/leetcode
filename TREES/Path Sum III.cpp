/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                helper(t,sum,0);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return ans;
    }
    private:
    void helper(TreeNode* root,int sum,int curr)
    {
        if(!root)return;
        curr+=root->val;
        if(curr==sum)ans++;
        helper(root->left,sum,curr);
        helper(root->right,sum,curr);
    }
};
