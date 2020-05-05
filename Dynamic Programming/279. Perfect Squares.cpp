/*
there are many approaches to solve this problem.
I will be using dp to solve this.
*/
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            dp[i]=i;
            for(int j=1;j<=sqrt(i);j++)
            {
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
