/*
The way to approach this problem is to use a breadth first search.
The way to distinguish a bfs and a dfs is that bfs slowly keeps bulding and becoming bigger whereas a depth first search is where u a a node
and plunge through all of its neighbors until u reach a base condition.
*/
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0,ans=-1; //ans is set to 0 because at the 0th minute we see in the pic the intial stage where 1 element is duplicated which havent encountered yet.
        queue<pair<int,int>> q;//This is like a first 2 u encounter u store into a queue after which using thiese indices and the direction matrix below will be able to duplicate ur rotten oranges
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}}; //We create direction map that helps us move in either of the 4 directions.
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)count++;  //0 is useless to us because the duplication wont get affected in these cells
                if(grid[i][j]==2)q.push({i,j}); //We push these indices which will used to duplicate 4 dirctionally later
            }
        }
        while(!q.empty())
        {
            int n=q.size();
            ans++;               //here is our answer it starts with 0th minute thats why ans was initialized as -1
            for(int i=0;i<n;i++)
            {
                count--;                    //for each cell 1 or 2 we decrement count cuz we want to know whether we hit all of the cells containing 1 and 2 or not
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<dir.size();i++)
                {
                    int x=p.first+dir[i][0];  //we check x and y dirction to check for cell1 so we can duplicate it
                    int y=p.second+dir[i][1];
                    if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]!=1)continue;
                    grid[x][y]=2;
                    q.push({x,y});
                }
            }
        }
        if(count==0)return max(0,ans);//we have 0 because if we use this only to tackle the case of [[0]] here it takes 0 minutes to duplicate because it doesnt need duplication
        return -1;
    }