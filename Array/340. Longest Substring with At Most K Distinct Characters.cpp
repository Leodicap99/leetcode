    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int j=0,ans=0;
        unordered_map<char,int> map;
        for(int i=0;i<s.size();i++)
        {
            map[s[i]]++;
            while(map.size()>k)
            {
                map[s[j]]--;
                if(map[s[j]]==0)map.erase(s[j]);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
