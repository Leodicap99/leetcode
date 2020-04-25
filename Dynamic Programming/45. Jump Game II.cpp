/*
The approach we ll be taking is DP. 
Remainder: This is an O(n^2) solution.
Like any other tyical DP question we ask ourselves at the currnt index how many minimum jumps did i take to get here.
I will be creating a dp array where the ith location denoted the minimum jumps i took to get there.
lets assum 
nums =  [2,3,1,1,4]
index = [0,1,2,3,4]

At the initial position the minimum jumps taken to reach there would be 0.
Thus this will be our base case.
For the next case:
now we check if 2+0>=i(1) which is true then 
dp[i] = min(dp[i],dp[j]+1) (Note that dp will be holding mximum values at the beginning)
      = 1
      thus dp = [0,1]

      dp = [0,1,1]  (first index jump)
      dp = [0,1,1,2] (second index jump)
      dp = [0,1,1,2,2] (second index jump)

      thus 2 is our final answer!
*/
     int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX);
        dp[0]=0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]+j>=i)
                {
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[nums.size()-1];
    }