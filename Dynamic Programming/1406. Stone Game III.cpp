class Solution {
public:
    int dp[50001];
    int help(vector<int>& s,int i)
    {
        if(i>=s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        ans=max(ans,s[i]-help(s,i+1));
        if(i+1<s.size())ans=max(ans,s[i]+s[i+1]-help(s,i+2));
        if(i+2<s.size())ans=max(ans,s[i]+s[i+1]+s[i+2]-help(s,i+3));
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& s) {
        for(int i=0;i<s.size();i++)dp[i]=-1;
        int ans=help(s,0);
        if(ans>0)return "Alice";
        else if(ans==0)return "Tie";
        return "Bob";
    }
};
