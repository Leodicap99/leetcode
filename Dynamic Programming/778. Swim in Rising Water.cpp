class Solution {
public:
    int dp[51][51];
    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
    void dfs(vector<vector<int>>& grid,int i,int j,int curr)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid.size()||max(curr,grid[i][j])>=dp[i][j])return;
        dp[i][j]=max(curr,grid[i][j]);
        for(auto &x:dir)
            dfs(grid,i+x[0],j+x[1],dp[i][j]);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)dp[i][j]=1e9;
        }
        dfs(grid,0,0,grid[0][0]);
        return dp[n-1][n-1];
    }
};
