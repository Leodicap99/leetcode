/*
This is a typical depth first problem,
What we do is to plunge though all the possible neighbours of a one making them 0s and this will be considered as an island.
Let input be 
     
     11110
	 11010
     11000
     00000

Now we trverse through the grid and if we find a 1 we will make all of its neighbors 0s.
Here at grid[0][0] ='1' so we will make all ofits neighbors '0'.

     00000
	 00000
     00000
     00000

Thus you can see  that now we cant see an island anymore thus the total numbber of islands are 1.
Lets take another example:

     11110
	 11010
     11000   
     00011

grid[0][0]='1' we plunge through all of its neighbors and make the neighbors 0.
     
     00000
	 00000
     00000  <------count=1
     00011

Now if we notice there are still ones present.
grid[3][3] = '1' we plunge through all of its neighbors and make it '0'.
    
     00000
	 00000
     00000 <----count=2
     00000

Thus there are 2 islands now.
*/
    int dfs(int i,int j,vector<vector<char>>& grid)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0')return 0;
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
      if(grid.size()==0)return 0;
        int count=0;
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[0].size();j++)
           {
               if(grid[i][j]=='1')
               {
                   count+=dfs(i,j,grid);
               }
           }
       }
        return count;
    }