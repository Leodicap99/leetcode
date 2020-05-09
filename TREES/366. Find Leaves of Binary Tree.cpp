/*
We record the depth of each of the nodes in the tree using an unordered map and according to their depths we push it into our matrix.
          1
         / \
        2   3
       / \     
      4   5 

We use a depth function that maps the node to its depth.

map 
1->2
2->1
3->0(because nod child nodes)
4->0
5->0

Then u can use any of ur traversals and push the integer into the mapped location in the matrix.
 _           _
|  4  5   3   |
|             |
|     2       |
|             |
|_    1      _|

 */
    unordered_map<TreeNode*,int> map;
    vector<vector<int>> ans;
    int depth(TreeNode* root)
    {
        if(!root)return -1;
        map[root]=max(depth(root->left),depth(root->right))+1;
        return map[root];
    }
    void build(TreeNode* root)
    {
        if(!root)return;
        build(root->left);
        ans[map[root]].push_back(root->val);
        build(root->right);
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        int d=depth(root);
        ans=vector<vector<int>>(d+1);
        build(root);
        return ans;
    }
