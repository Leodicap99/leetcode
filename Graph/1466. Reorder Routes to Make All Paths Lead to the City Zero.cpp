class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> indegree(n),outdegree(n);
        for(auto &x:connections)
        {
            outdegree[x[0]].push_back(x[1]);
            indegree[x[1]].push_back(x[0]);
        }
        queue<int> q;
        int ans=0;
        unordered_set<int> s;
        s.insert(0);
        for(auto &x:outdegree[0])
        {
            ans++;
            q.push(x);
            s.insert(x);
        }
        for(auto &x:indegree[0])
        {
            q.push(x);
            s.insert(x);
        }
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            s.insert(t);
            for(auto &x:outdegree[t])
            {
                if(s.find(x)==s.end())
                {ans++;
                q.push(x);
                }
            }
            for(auto &x:indegree[t])
            {
                if(s.find(x)==s.end()){
                q.push(x);
                }
            }
        }
        return ans;
    }
};
