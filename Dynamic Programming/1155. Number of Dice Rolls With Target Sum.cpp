/*
We will implement the answer using a dp matrix
We will try to find a pattern out of the matrix and finally derive pur solution.
Let d = 2, f = 6, target = 7

Let our location (i,j) denote the number of ways to reachh target j using i number of dices.

        0 1 2 3 4 5 6 7
      0
      1
      2
for target 1 using 1 dice total number of ways is 1 so will 2,3,...6
however for 7 we cannot get 7 using 1 dice let us try thinking of a way to implement a fromula from this.
we know that any number>6 should be 0 for 1 no of dice 
so we can implement this by adding a row above which says for dp[i][j]=dp[i-1][j-k] where k is the maximum faces it can have

        0 1 2 3 4 5 6 7
      0 1 0 0 0 0 0 0 0
      1 1 1 1 1 1 1 1 0     <----------DP MATRIX
      2

      So if we encounter a target greater than k it will be assigned as 0.

      What will happen ifmy target is 1 but number of dices are 2?
      The number of ways is 0 right?
      Hence we put a condition if (k>target) do nothing

        0 1 2 3 4 5 6 7
      0 1 0 0 0 0 0 0 0
      1 0 1 1 1 1 1 1 0     <----------DP MATRIX
      2 0 0 1 2 3 4 5 6

      We use the same logic as before 
      as d>target 1 is assigned as 0
      dp[i][j] = dp[i][j] + dp[i-1][j-k] <---the only difference is that we will be taking the cummulative sum of all the targets and build our solution.
*/
        int numRollsToTarget(int d, int f, int target) {
        int m=pow(10,9)+7;
        vector<vector<int>> dp(d+1,vector<int>(target+1));
        dp[0][0]=1;
        for(int i=1;i<=d;i++)
        {
            for(int j=1;j<=target;j++)
            {
                for(int k=1;k<=f;k++)
                {
                    if(k<=j)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-k])%m;
                }
            }
        }
        return dp[d][target];
    }      

