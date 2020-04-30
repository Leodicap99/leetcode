/*
Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree

Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree. 

We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.

Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation: 
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
Other valid sequences are: 
0 -> 1 -> 1 -> 0 
0 -> 0 -> 0
*/

ANSWER:

    bool dfs(TreeNode* root,vector<int>& arr,int index)
    {
        if(!root)return false;
        if(index==arr.size()-1 && !root->left && !root->right &&root->val==arr[index])return true;
        else if(index<arr.size()&&root->val==arr[index])
            return dfs(root->left,arr,index+1)||dfs(root->right,arr,index+1);
        else
            return false;
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(!root)return arr.size()==0;
        return dfs(root,arr,0);
    } 