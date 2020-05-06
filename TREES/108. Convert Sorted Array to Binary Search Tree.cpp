/*
Divide and Conquer:-

As the tree is heightbalanced the root will be present at the n/2 location of the nums array where n is the size of the array.
So we can use this base case to build our tree
[-10,-3,0,5,9]

0 will be the root.
Then we pass the left part of the array to root->left and right part of the array to root right and repeat the same procedure.


1.    0


root->left = build(nums,l,m-1)

|      |
|  -10 |
|  -3  |
|______|

2.   0
    /
  -10
    \
    -3

and we repeat this procedure to get the answer
*/

    {
        if(l>r)return NULL;
        int m=(l+r)/2;
        TreeNode* newnode=new TreeNode(nums[m]);
        newnode->left=makeBST(nums,l,m-1);
        newnode->right=makeBST(nums,m+1,r);
        return newnode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums,0,nums.size()-1);
    }