/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,map<int,set<int>>> map;
    void inorder(TreeNode* root,int x,int y)
    {
        if(!root)return;
        inorder(root->left,x-1,y+1);
        map[x][y].insert(root->val);
        inorder(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorder(root,0,0);
        vector<vector<int>> ans;
        for(auto it:map)
        {
            vector<int> col;
            for(auto p:it.second)
            {
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
