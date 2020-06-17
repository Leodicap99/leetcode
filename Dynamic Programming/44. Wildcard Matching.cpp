class Solution {
public:
    bool isMatch(string s, string p) {
        int start=0;
        bool first=true;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]=='*')
            {
                if(first)p[start++]=p[i],first=false;
            }
            else
            {
                p[start++]=p[i];
                first=true;
            }
        }
        p=p.substr(0,start);
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0]=true;
        if(p[0]=='*')dp[0][1]=true;
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[s.size()][p.size()];
    }
};
