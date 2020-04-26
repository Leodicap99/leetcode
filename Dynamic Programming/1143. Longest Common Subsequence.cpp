/*
Always use a dp table to solve questions related to dp.
Although it might not yield the most optimal solution (usually o(n^2)) it can be used to understand dp well for beginners.
Here in my dp table the ith row signifies what is maximum susbesquence length that i got gained so far.
In order to get such an answer lets try to device our logic as such:
if my string characters match i will take dp[i-1][j-1] + 1 (Since we are trying to match characters by characters)
if not take the maximum of dp[i-1][j] &&dp[i][j-1].Why?
	Becasue we are trying to find the longest subsequence and not substring.S we will have to keep propagating the maximum length of the 
Commom subsequence throughout the dp array in order to yield out final answer.
Let
text1 = "abcde", text2 = "ace" .
  
    0 a c e
  0 0 0 0 0
  a 0 1 1 1
  b 0 1 1 1
  c 0 1 2 2
  d 0 1 2 2
  e 0 1 2 3

  thus the final answer is dp[text1.length()][text2.length()].
  */
      int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1));
        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }