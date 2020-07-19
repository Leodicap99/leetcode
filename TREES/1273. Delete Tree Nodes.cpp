/*
A tree rooted at node 0 is given as follows:

    The number of nodes is nodes;
    The value of the i-th node is value[i];
    The parent of the i-th node is parent[i].

Remove every subtree whose sum of values of nodes is zero.

After doing so, return the number of nodes remaining in the tree.
*/


class Solution {
public:
    vector<bool> dp;
    int dfs(int u,vector<vector<int>>& graph,vector<int>& value)
    {
        int sum=value[u];
        for(auto x:graph[u])
            sum+=dfs(x,graph,value);
        if(sum==0)dp[u]=true;
        return sum;
    }
    int dfs(int u,vector<vector<int>>& graph)
    {
        if(dp[u])return 0;
        int ans=1;
        for(auto x:graph[u])
            ans+=dfs(x,graph);
        return ans;
    }
    int deleteTreeNodes(int n, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> graph(n);
        dp.resize(n);
        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]==-1)continue;
            graph[parent[i]].push_back(i);
        }
        dfs(0,graph,value);
        return dfs(0,graph);
    }
};
