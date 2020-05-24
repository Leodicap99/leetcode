
class Solution {
public:
    TreeNode* build(TreeNode* root,int x)
    {
        if(!root)
        {
            root=new TreeNode(x);
            return root;
        }
        if(root->val>x)root->left=build(root->left,x);
        if(root->val<x)root->right=build(root->right,x);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(int &x:preorder)
        {
            root=build(root,x);
        }
        return root;
    }
};
