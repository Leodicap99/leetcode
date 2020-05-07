/*
Credits to :-https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/discuss/573840/C%2B%2B-DFS-100-Space-and-Faster-than-76

We will be solving w be solving this using dfs.

Our idea of solving will be to start from top left corner and work ourselves to the bottom right corner.

We keep a visited boolean array that tells about each cell wether it is visited or not.
All we want to do in this question is to check if the bottommost right cell is visited or not.
*/
class Solution {
public:
    bool isvalid(int x,int y,vector<vector<int>> &grid)                //This is a boolean function to check we are within the matrix.
    {
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size())return false;
        return true;
    }
    void dfs(int x,int y,vector<vector<bool>> &vis,vector<vector<int>> &grid)
    {
        if(vis[x][y])return;                //We dont want to backtrack our visited steps
        vis[x][y]=true;
        int up,down,left,right;
        up=down=left=right=0;                //These are intuitiv just look at the diagram 
        if(grid[x][y]==1)
            left=right=1;
        else if(grid[x][y]==2)
            up=down=1;
        else if(grid[x][y]==3)
            left=down=1;
        else if(grid[x][y]==4)
            down=right=1;
        else if(grid[x][y]==5)
            left=up=1;
        else
            up=right=1;
        if(up)
        {
            int new_x=x-1,new_y=y;            //Think this in terms of the matrix and not the routes.I can go up a cell means i can go up a row which mean i-1
            if(isvalid(new_x,new_y,grid) && (grid[new_x][new_y]==2||grid[new_x][new_y]==3||grid[new_x][new_y]==4))  //The way to get the second part of the if case is to check from my current cell what all routes will allow me to go up
                dfs(new_x,new_y,vis,grid);
        }
        if(down)
        {
            int new_x=x+1,new_y=y;
            if(isvalid(new_x,new_y,grid) && (grid[new_x][new_y]==2||grid[new_x][new_y]==5||grid[new_x][new_y]==6))
                dfs(new_x,new_y,vis,grid);
        }
        if(right)
        {
            int new_x=x,new_y=y+1;
            if(isvalid(new_x,new_y,grid) && (grid[new_x][new_y]==1||grid[new_x][new_y]==5||grid[new_x][new_y]==3))
                dfs(new_x,new_y,vis,grid);
        }
        if(left)
        {
            int new_x=x,new_y=y-1;
            if(isvalid(new_x,new_y,grid) && (grid[new_x][new_y]==1||grid[new_x][new_y]==4||grid[new_x][new_y]==6))
                dfs(new_x,new_y,vis,grid);
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)return false;
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));           //Boolean array with the size of grid checking if a cell is visited or not
        dfs(0,0,vis,grid);                                           //We start our dfs function from top left corner and work ourselves to the bottom right corner.
        return vis[n-1][m-1];                                       //All we care about is if the last cell is visited or not.
    }
};
