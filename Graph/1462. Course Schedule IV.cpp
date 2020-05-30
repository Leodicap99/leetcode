class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_set<int>> v(n);
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for(auto &x:prerequisites)
        {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(auto &x:graph[t])
            {
                if(--indegree[x]==0)q.push(x);
                v[x].insert(t);
                for(auto &p:v[t])v[x].insert(p);
            }
        }
        vector<bool> seen;
        for(int i=0;i<queries.size();i++)
        {
            if(v[queries[i][0]].count(queries[i][1]))seen.push_back(true);
            else
                seen.push_back(false);
        }
        return seen;
    }
};
