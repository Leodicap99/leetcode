class Solution {
public:
    using pii=pair<int,int>;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> grr(n),grb(n);
        for(auto &x:red_edges)
            grr[x[0]].push_back(x[1]);
        for(auto &x:blue_edges)
            grb[x[0]].push_back(x[1]);
        vector<vector<int>> vis(n,vector<int>(2,0));
        queue<pii> q;
        q.push({0,0});
        q.push({0,1});
        vis[0][0]=1;
        vis[0][1]=1;
        int d=0;
        vector<int> ans(n,-1);
        while(!q.empty())
        {
            int len=q.size();
            while(len-->0)
            {
                pii p=q.front();
                q.pop();
                if(ans[p.first]==-1)ans[p.first]=d;
                auto graph=p.second?grr:grb;
                int color=p.second?0:1;
                for(auto &x:graph[p.first])
                {
                    if(vis[x][color])continue;
                    vis[x][color]=1;
                    q.push({x,color});
                }
            }
            d++;
        }
        return ans;
    }
};
