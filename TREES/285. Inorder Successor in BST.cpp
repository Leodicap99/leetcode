/*
We tackle this problem just by doing a simple traversal by using a while loop.
Binary seach trees are formed in such a way such that left child will hold a value lesser than parent and right child will hold value
greater than parent.
We use a while loop to traverse the BST due to the above property.
If root->val <= p->val move root to its right child as the right child is greater.
Else we store succ as root and keep proceeding to the left hild as we want the minimum element greater than p->val.

root = [5,3,6,2,4,null,null,1], p = 4

               5  <----root
              /\ 
             3  6
            / \
           2   4
          /
         1
root->val>root->left thus we store succ as 5

we move root->left

               5  <----root
              /\ 
    root-->  3  6
            / \
           2   4
          /
         1
As root->val<p->val we move to root->right which is 4 so we again move right which is NULL.

Thus suc=5 will be the final answer.

*/
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root||!p)return NULL;
        TreeNode* suc=NULL;
        while(root)
        {
            if(root->val<=p->val)
            {
                root=root->right;
            }
            else
            {
                suc=root;
                root=root->left;
            }
        }
        return suc;
    }