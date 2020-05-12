/*
The algorithm to solve this is 
1. print the root node val.
2. print left node vals except for leaves.
3. print the left leaves.
4. print the right leaves.
5. print the right nodes.
*/
    vector<int> ans;
    void printleft(TreeNode* root)
    {
        if(!root || (!root->left&&!root->right))return;
        ans.push_back(root->val);
        if(!root->left)printleft(root->right);
        else
            printleft(root->left);
    }
    void printleaf(TreeNode* root)
    {
        if(!root)return;
        printleaf(root->left);
        if(!root->left && !root->right)ans.push_back(root->val);
        printleaf(root->right);
    }
    void printright(TreeNode* root)
    {
        if(!root || (!root->left && !root->right))return;
        if(!root->right)printright(root->left);
        else printright(root->right);
        ans.push_back(root->val);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root)return ans;
        ans.push_back(root->val);
        printleft(root->left);
        printleaf(root->left);
        printleaf(root->right);
        printright(root->right);
        return ans;
    }