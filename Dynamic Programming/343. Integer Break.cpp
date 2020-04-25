This question is an unbounded knapsack problem.How to aprroach this problem is by thinking when im at a number if a sum of two numbers
is equal to me find the maximum product of them or find the maximum product of their individual sums.
Let n=5
      1 2 3 4 5
      1 2 2 4 ?
      You might be thinking why for 2 the maximum product is 2. This is because this is the only exception in this problem.
      for 5->1+4=1*4=4
             1*2*2=4(4 is split at two 2s)
             2+3 =2*3 =6
             2+2+1=2*2*1=4
             1+1+3=3*1*1=3
            Thus the maximum is 6.
     Now how do we code this algorithm?
     we create a dp matrix that says at ith state the best possible product is dp[i] with an exception of 2!


        int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        int maxans=0;
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                maxans=max(maxans,j*dp[i-j]);
            }
            if(i==n)dp[i]=max;<---------------//This is because we cannot consider the number itself because the product will be minimum as n and 0.
            else
            dp[i]=max(i,maxans);
        }
        return dp[n];
    }