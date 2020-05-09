/*
We do a postorder traversal on the binary tree.

There are 2 ways as to how a univalue subtree can exist:-

1. If the node is the leaf of the tree.
2. If the root->val is equat to its left and right subtree while making sure the children satisfy the property too.


              5
             / \
            1   5
           / \   \
          5   5   5

ans=0

          |           |
          |           |
          |    5      |           <-----Recursion Stack
          |    1      |
          |    5      |
          |___________|

As 5 is the leaf node we increment our answer.
ans=1

5 is popped out of the stack and 1 is analyzed.


          |           |
          |           |
          |    5      |           <-----Recursion Stack
          |    1      |
          |    5      |
          |___________|

As 5 is the leaf node we increment our answer.
ans=2

          |           |
          |           |
          |           |           <-----Recursion Stack
          |    1      |
          |    5      |
          |___________|

Thous both its children satisfied the condition it didnt as its value isnt equal to that of the childrens
ans=2

          |           |
          |           |
          |    5      |           <-----Recursion Stack
          |    5      |
          |    5      |
          |___________| 


As 5 is the leaf node our answer gets incremented.
ans=3
5 is popped out.

          |           |
          |           |
          |           |           <-----Recursion Stack
          |    5      |
          |    5      |
          |___________|

As 5's child satisfied the condition and its value is equal to the child's value answer gets incremented.
ans=4

          |           |
          |           |
          |           |           <-----Recursion Stack
          |           |
          |    5      |
          |___________|

5 doesnt satisfy the condition and gets popped out.

Thus our answer is 4.
*/
    bool helper(TreeNode* root,int &ans)
    {
        if(!root)return true;
        bool l=helper(root->left,ans);
        bool r=helper(root->right,ans);
        bool res=l && r && (!root->left || root->val==root->left->val) && (!root->right||root->val==root->right->val); //Making sure that its either leaf node or a parent node thats equal to its children nodes.
        ans+=res;
        return res;
    }
    int countUnivalSubtrees(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }

