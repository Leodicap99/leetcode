/*
First for this question u should be able to print all paths from root to leaf
Cuz only after this do we convert it to decimal and proceed
I would suggest u guys to solve this first and then jump into this.
https://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/

So instead of printing the solution we call a funcion called convert to decimal.
Note that when u have been pushing elements into ur array the one with 0 index is ur most significant bit.

So to covert it all we have to do is n=n*2+v[i] where i is from 0 to v.size()-1

Code:-
*/
    int ans=0;
    int convert_decimal(vector<int> v)
    {
        int n=0;
        for(int i=0;i<v.size();i++)
            n=n*2+v[i];
        return n;
    }
    void findpath(TreeNode* root,vector<int> t)
    {
        if(!root)return;
        t.push_back(root->val);
        if(!root->left && !root->right)ans+=convert_decimal(t);
        findpath(root->left,t);
        findpath(root->right,t);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root)return 0;
        vector<int> t;
        findpath(root,t);
        return ans;
    }