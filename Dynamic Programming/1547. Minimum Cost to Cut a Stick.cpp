class Solution {
public:
    int dp[102][102];
    int helper(vector<int>& cuts,int l,int r)
    {
        if(l+1==r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        dp[l][r]=INT_MAX;
        for(int i=l+1;i<r;i++)
        {
            dp[l][r]=min(dp[l][r],cuts[r]-cuts[l]+helper(cuts,l,i)+helper(cuts,i,r));
        }
        return dp[l][r];
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        return helper(cuts,0,cuts.size()-1);
    }
};
