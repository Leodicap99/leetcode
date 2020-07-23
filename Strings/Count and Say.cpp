class Solution {
public:
    string helper(string s)
    {
        string ans;
        for(int i=0;i<s.size();i++)
        {
            int count=1;
            while(i+1<s.size() && s[i]==s[i+1])
            {
                i++;
                count++;
            }
            ans+=to_string(count)+s[i];
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++)
            ans=helper(ans);
        return ans;
    }
};
