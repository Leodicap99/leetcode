class Solution {
public:
    int dp[101][21][101];
    int help(int i,int l,int t,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        if(dp[i][l][t]!=-1)return dp[i][l][t];
        if(t>target)return INT_MAX/2;
        if(i==m)
        {
            if(target==t)return 0;
            else return INT_MAX/2;
        }
        int ans=INT_MAX/2;
        if(houses[i]==0)
        {
            for(int j=0;j<n;j++)
            {
                ans=min(ans,cost[i][j]+help(i+1,j+1,(l==j+1)?t:t+1,houses,cost,m,n,target));
            }
        }
        else
        {
            ans=min(ans,help(i+1,houses[i],(l==houses[i])?t:t+1,houses,cost,m,n,target));
        }
        return dp[i][l][t]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof dp);
        return help(0,0,0,houses,cost,m,n,target)==INT_MAX/2?-1:help(0,0,0,houses,cost,m,n,target);        
    }
};
