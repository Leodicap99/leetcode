    int countServers(vector<vector<int>>& grid) {
        vector<int> row(grid.size());
        vector<int> col(grid[0].size());
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                    row[i]++,col[j]++;                 //For each row and column we increment it
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] && (col[j]>1 || row[i]>1))   //If int the same row or colum there is another server increment it
                    ans++;
            }
        }
        return ans;
    }