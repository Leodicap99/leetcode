class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans,indegree(n);
        vector<vector<int>> graph(n);
        for(auto &x:prerequisites)
        {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        int count=0;
        for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto &x:graph[t])
            {
                if(--indegree[x]==0)q.push(x);
            }
            count++;
        }
        if(count!=n)return {};
        return ans;
    }
};
