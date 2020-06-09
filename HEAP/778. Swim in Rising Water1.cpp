class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        using pii=pair<int,pair<int,int>>;
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int seen[n][n];
        memset(seen,0,sizeof seen);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({grid[0][0],{0,0}});
        int ans=0;
        seen[0][0]=1;
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            ans=max(ans,p.first);
            if(p.second.first==n-1 && p.second.second==n-1)return ans;
            for(auto &a:dir)
            {
                int x=p.second.first+a[0];
                int y=p.second.second+a[1];
                if(x<0||y<0||x>=n||y>=n||seen[x][y])continue;
                seen[x][y]=1;
                pq.push({grid[x][y],{x,y}});
            }
        }
        return -1;
    }
};
