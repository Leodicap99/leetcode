class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(vector<string> &rows,int row,int col,int n)
    {
        for(int i=0;i<row;i++)
            if(rows[i][col]=='Q')return false;
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(rows[i][j]=='Q')return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
            if(rows[i][j]=='Q')return false;
        return true;
    }
    void solve(vector<string> &rows,int row,int n)
    {
        if(row==n)
        {
            ans.push_back(rows);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(isValid(rows,row,col,n))
            {
                rows[row][col]='Q';
                solve(rows,row+1,n);
                rows[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> row(n,string(n,'.'));
        solve(row,0,n);
        return ans;
    }
};
