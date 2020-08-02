class Solution {
    unordered_map<TreeNode*, vector<TreeNode*>>mp;
    vector<TreeNode*>leaves;
    int ans = 0;
    
    void storeLeaves(TreeNode* root) {
        if (!root) return;
        storeLeaves(root->left);
        if (!root->left && !root->right)
            leaves.push_back(root);
        if (root->left) {
            mp[root].push_back(root->left);
            mp[root->left].push_back(root);
        }
        if (root->right) {
            mp[root].push_back(root->right);
            mp[root->right].push_back(root);
        }
        storeLeaves(root->right);
    }
    
    void bfs(TreeNode* v, int distance) {    
        queue<TreeNode*>q;
        q.push(v);
        int dist = 0;
        
        unordered_map<TreeNode*, bool>visited;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (visited[node]) continue;
                if (node != v && !node->left && !node->right)
                    ans++;
                visited[node] = true;
                for (auto j = 0; j < mp[node].size(); j++)
                    q.push(mp[node][j]);
            }
            dist++;
            if (dist > distance) return;
        }
    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        if (!root) return 0;
        storeLeaves(root);
        for (int i = 0; i < leaves.size(); i++)
            bfs(leaves[i], distance);
        return ans/2;
    }
};
