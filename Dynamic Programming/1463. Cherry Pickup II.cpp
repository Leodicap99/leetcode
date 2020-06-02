class Solution {
public:
    int dp[71][71][71];
    int help(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid)
    {
        if(j1<0||j2<0||i>=n||j1>=m||j2>=m)return 0;
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int ans=grid[i][j1]+(j1==j2?0:grid[i][j2]);
        int count=0;
        for(int x=-1;x<2;x++)
        {
            for(int y=-1;y<2;y++)
            {
                count=max(count,help(i+1,j1+x,j2+y,n,m,grid));
            }
        }
        return dp[i][j1][j2]=ans+count;
    }
    int cherryPickup(vector<vector<int>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof dp);
        return help(0,0,m-1,n,m,grid);
    }
};
