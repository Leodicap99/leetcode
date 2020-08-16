/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int dfs(Node* root,int &ans)
    {
        if(!root)return 0;
        int max1=0,max2=0;
        for(Node* a:root->children)
        {
            int height=dfs(a,ans);
            if(height>max1)
            {
                max2=max1;
                max1=height;
            }
            else if(height>max2)max2=height;
        }
        ans=max(ans,max1+max2);
        return max1+1;
    }
    int diameter(Node* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};
