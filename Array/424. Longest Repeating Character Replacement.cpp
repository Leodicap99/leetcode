/*
Here the important thing to note is that the most repeating character not necessarily have to produce the longest substring.
when we are iterating through the loop at present what is the most repeating character will be used in our slidng window
whilst we cache in our maximum.
*/
    int characterReplacement(string s, int k) {
        unordered_map<char,int> map;
        
        int i=0,j=0,ans=0,same=0;
        for(i=0;i<s.size();i++)
        {
            same=max(same,++map[s[i]]);
            while(i-j-same+1>k)
            {
                map[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }