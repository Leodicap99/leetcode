class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,0);
        dp[0]=1;
        dp[1]=(s[0]!='0')?1:0;
        for(int i=2;i<=s.length();i++)
        {
            int one=s[i-1]-'0';
            int two=stoi(s.substr(i-2,2));
            if(one>0)dp[i]=dp[i-1];
            if(two>=10 && two<=26)dp[i]+=dp[i-2];
        }
        return dp[s.length()];
    }
};
