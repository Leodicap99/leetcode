    int numKLenSubstrNoRepeats(string s, int k) {
        int ans=0;
        vector<int> ch(26,0);
        for(int i=0;i<s.size();i++)
        {
            ch[s[i]-'a']++;
            if(i>=k)
            {
                ch[s[i-k]-'a']--;
            }
                int count=0;
                for(int j=0;j<26;j++)count+=ch[j]==1?1:0;
                if(count==k)ans++;
        }
        
        return ans;
    }
