class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0)return;
        grid[i][j]=0;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    bool disconnected(vector<vector<int>> grid)
    {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    dfs(i,j,grid);
                cout<<count+1<<" ";
                if(++count>1)return true;
                }
            }
        }
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        if(disconnected(grid))return 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)continue;
                grid[i][j]=0;
                if(disconnected(grid))return 1;
                grid[i][j]=1;
            }
        }
        return 2;
    }
};
