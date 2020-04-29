/*
The way to think of a solution to this is that when we are looking a path in a tree its unidirectional and cannot retrace back what i mean by that is:
    _
  / 1 \ 
 / / \ \ <-----path that goes like a depth first search without backtracking
/ 2   3 v  

S a way to solve this is that if i am at a node i can choose a left or right subtree but if i choose both this is the only subtree that will contain my maximum

I first set my max_sum to infinity.
I can do either either of the options presented:
1.I can choose to take up the left subtree or drop it.
2.I can either choose to take up the right subtree or drop it.
3.I check for a possibility whether if i were to take both left subtree and right subtree would that beat my current max_sum?
Lets consider
   -10
   / \
  9  20
    /  \
   15   7
I do my postorder traversal with a bit of variation:-

int l=max(max_gain(root->left),0);
int r=max(max_gain(root->right),0);
But why?
This is because I have the option to choose the left or right subtree or whether i will just settle with my root value.

So I do my regular postorder traversal and do the above steps
I hit 9

    9
   / \
NULL  NULL

int l=0,r=0(Base condition)
i store the value of 9+0+0 in a variable
Then check if this is greater than maxsum or not is so i update it.
As my max_sum was INT_MIN it gets updated to 9

Now we explore the right tree of root which reaches 15

    15
   / \
NULL  NULL

int l=0,r=0(Base condition)
i store the value of 9+0+0 in a variable
Then check if this is greater than maxsum or not is so i update it.
As my max_sum was 9 it gets updated to 15

Similarly with 7 but 7 doesnt beat the max_sum so nothing happens.

Now we backtrack 20
here int r=9(as 9>0)
     int l=15(as 15>0)
 now i check whether 20+15+9(considering this subtree to be my maximum)
 as 42>15 max_sum=42
 Now what if we dont consider this subtree?

 Then we choose 20 and maximum of its left or right subtree
 so we send return root->val+max(l,r) to our recursion stack
 so when i reach the root it would be like this
           -10
           /  \    <----I considered 15 and 20 because its along a path and is greater than 20+7
          9    35
  int l=9
      r=35
      check whether 9+35+-10=34 beats max_sum
      34<42 so nothing happens and we return -10+max(9,35)=25 to the caller after which we break out of the helper function and we get max_sum as 42.
*/
    int max_sum=INT_MIN;
    int max_gain(TreeNode* root)
    {
        if(!root)return 0;
        int l=max(max_gain(root->left),0);
        int r=max(max_gain(root->right),0);
        int new_price=root->val+l+r;
        max_sum=max(max_sum,new_price);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }