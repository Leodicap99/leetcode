class Solution {
public:
    using pii=pair<int,int>;
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    int bfs(vector<vector<int>>& forest,int i,int j,int er,int ec)
    {
        if(i==er && j==ec)return 0;
        int n=forest.size(),m=forest[0].size();
        queue<pii> q;
        q.push({i,j});
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int steps=0;
        vis[i][j]=1;
        while(!q.empty())
        {
            int size=q.size();
            steps++;
            for(int i=0;i<size;i++)
            {
                pii p=q.front();
                q.pop();
                for(auto &a:dirs)
                {
                    int x=a[0]+p.first;
                    int y=a[1]+p.second;
                    if(x<0||y<0||x>=n||y>=m||vis[x][y]||forest[x][y]==0)continue;
                    vis[x][y]=1;
                    if(x==er && y==ec)return steps;
                    q.push({x,y});
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size(),m=forest[0].size();
        vector<vector<int>> trees;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(forest[i][j]>1)
                    trees.push_back({forest[i][j],i,j});
            }
        }
        sort(trees.begin(),trees.end());
        int ans=0;
        for(int i=0,curr_row=0,curr_col=0;i<trees.size();i++)
        {
            int steps=bfs(forest,curr_row,curr_col,trees[i][1],trees[i][2]);
            if(steps==-1)return -1;
            ans+=steps;
            curr_row=trees[i][1];
            curr_col=trees[i][2];
        }
        return ans;
    }
};
