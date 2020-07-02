int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;i-j>=0 && i+j<n && s[i-j]==s[i+j];j++)ans++;
            for(int j=0;i-j-1>=0 && i+j<n && s[i-j-1]==s[i+j];j++)ans++;
        }
        return ans;
    }
