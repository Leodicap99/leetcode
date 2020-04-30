/*
The way to tackle this problem is to do a depth first search and ask yourself will this node accept the condition if so how to build it in my final tree.
Now we have 
	3
   / \
  0   4
   \
    2
   /
  1

  L=1,R=3

  we are first at 3 so what we do is a postorder traversal first

  postorder traversal goes like this : L R root

  1,2,0,4,3 <---this how the traversal will go like


   |          |
   |    1     |
   |    2     | <-----Recursion stack when we do the postorder traversal
   |    0     |
   |____3_____|

  So first we explore 1:
   root->left and root->right are NULL and the root->val falls in the range to we retun this root to the recursion stack

   |          |
   |          |
   |    2     | <-----1 is return to our recursion stack so 2->1(linkage will occur)
   |    0     |
   |____3_____|

   as 2 has no right it gets popped out of the stack.

   |          |
   |          |
   |          | 
   |    0     |
   |____3_____|

   Since 2 agreed to our condition it will we sent up the recursion stack.

   Since 0 doesnt agree to our conditions 2 will be sent up to 3 and 0 gets popped out
   |          |
   |          |
   |          | 
   |          |
   |____3_____|

   3->2 linkage will happen to 3s left 

            3
           /
          2         <---so far from left and right
         /
        1
   we continue with root->right now 

   |          |
   |          |
   |          | 
   |    4     |
   |____3_____|

   4 left and right are NULL so as 4 doest obey the condition simply NULL is sent up and now 4 and 3 are popped out.
*/
       TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)return NULL;
        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        return root->val<L?root->right:root->val>R?root->left:root;
    }