class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<unordered_map<int,double>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]][edges[i][1]]=succProb[i];
            graph[edges[i][1]][edges[i][0]]=succProb[i];
        }
        vector<double> ans(n,0.0);
        queue<int> q;
        q.push(start);
        ans[start]=1.0;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(auto &x:graph[t])
            {
                if(ans[t]*x.second>ans[x.first])
                {
                    ans[x.first]=ans[t]*x.second;
                    q.push(x.first);
                }
            }
        }
        return ans[end];
    }
};
