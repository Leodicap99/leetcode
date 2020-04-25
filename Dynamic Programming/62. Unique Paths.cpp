Whenever attempting a dp problem stating the number of ways try to find out that at my current poistion 
how many ways is possible for me to reach this position.
The first row and first column only 1 way will be possible because the only other way to reach this is either 
right or down which are the contraints of the problem.

let m=3,n=4;
  1 2 3 4
1 1 1 1 1
2 1 2 3 4  <----- DP Matrix  dp[i][j] = dp[i-1][j] + dp[i][j-1]  where i!=0 and j!=0
3 1 3 6 10

Thus there are 10 ways to go!


    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++)dp[i][0]=1;
        for(int i=0;i<n;i++)dp[0][i]=1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        return dp[m-1][n-1];
    }