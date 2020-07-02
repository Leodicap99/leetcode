class Solution {
public:
    string lcs(string s1,string s2)
    {
        vector<vector<string>> dp(s1.size()+1,vector<string>(s2.size()+1));
        for(int i=1;i<=s1.size();i++)
        {
            for(int j=1;j<=s2.size();j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                else dp[i][j]+=dp[i-1][j].size()>dp[i][j-1].size()?dp[i-1][j]:dp[i][j-1];
            }
        }
        return dp[s1.size()][s2.size()];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int i=0,j=0;
        string ans;
        for(char ch:lcs(str1,str2))
        {
            while(str1[i]!=ch)ans+=str1[i++];
            while(str2[j]!=ch)ans+=str2[j++];
            ans+=ch;
            i++;j++;
        }
        return ans+str1.substr(i)+str2.substr(j);
    }
};
