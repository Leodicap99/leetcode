/*
This is similar to the solution of common substring problem.
we create a dp matrix and match the the two arrays together.

Lets consider the example
A: [1,2,3,2,1]
B: [3,2,1,4,7]
    
    3 2 1 4 7   
  0 0 0 0 0 0
1 0 0 0 1 0 0
2 0 0 1 0 0 0    <--------The logic used here is that if arr[i]==arr2[i] then dp[i][j]=1+dp[i-1][j-1] else dp[i][j]=0
3 0 1 0 0 0 0
2 0 0 2 0 0 0
1 0 0 0 3 0 0 

After this we traverse thru dp to check for the maximum element and that is out answer =3.
*/

    int findLength(vector<int>& A, vector<int>& B) {
        if(A.size()==0&&B.size()==0)return true;
        if(A.size()==0||B.size()==0)return false;
        int ans=0;
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1));
        for(int i=1;i<=A.size();i++)
        {
            for(int j=1;j<=B.size();j++)
            {
                if(A[i-1]==B[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
            
        }
        return ans;
    }