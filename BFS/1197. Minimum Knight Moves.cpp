class Solution {
public:
    #define tr 303
    using pii=pair<int,int>;
    int minKnightMoves(int st, int d) {
        vector<vector<int>> dir={{-2,-1},{2,-1},{-2,1},{2,1},{-1,-2},{1,-2},{-1,2},{1,2}};
        queue<pii> q;
        q.push({0,0});
        bool vis[2*tr][2*tr];
        memset(vis,false,sizeof(vis));
        int count=0;
        vis[tr][tr]=true;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                pii p=q.front();
                q.pop();
                if(p.first==st && p.second==d)return count;
                for(auto &a:dir)
                {
                    int x=a[0]+p.first;
                    int y=a[1]+p.second;
                    if(!vis[x+tr][y+tr])
                    {
                        vis[x+tr][y+tr]=true;
                        q.push({x,y});
                    }
                }
            }
            count++;
        }
        return 0;
    }
};
