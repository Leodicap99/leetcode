/*
I ll first try to find the longest sequence with the root and i will then find it for the children using recursion.
There are two ways which can contribute to our sequence.
1. It can either increase from node->root->node.
2. Decrease from node->root->node

The way we can do this is by doing a postordere traversal to those nodes that satisfies root->val+1/root->val-1.
*/
    int helper(TreeNode* root,int par,int sum)
    {
        if(!root)return 0;
        if(root->val==par+sum)
            return max(helper(root->left,root->val,sum),helper(root->right,root->val,sum))+1;
        return 0;
    }
    int longestConsecutive(TreeNode* root) {
        if(!root)return NULL;
        int l1=0,l2=0,childmax=0;
        l1=helper(root->left,root->val,-1)+helper(root->right,root->val,1)+1;
        l2=helper(root->left,root->val,1)+helper(root->right,root->val,-1)+1;
        childmax=max(longestConsecutive(root->left),longestConsecutive(root->right));
        return max(l1,max(l2,childmax));
    }