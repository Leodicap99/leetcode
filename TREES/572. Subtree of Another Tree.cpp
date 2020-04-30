/*
The way to solve this problem is find the node of s which equals the root node of t. Once found we can use a function to check if every
node equals every other node.
       3            
      / \
-->  4   5
    / \
   1   2

   4 
  / \
 1   2

 Here as soon as we find 4 we just check if every node in s is equal to every other node in t 
*/

     bool issame(TreeNode* s,TreeNode* t)
    {
        if(!s&&!t)return true;
        if(!s||!t)return false;
        if(s->val!=t->val)return false;
        return s->val==t->val&&issame(s->left,t->left)&&issame(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)return false;
        return issame(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
    }