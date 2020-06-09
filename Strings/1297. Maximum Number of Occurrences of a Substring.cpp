class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans=0,start=0;
        unordered_map<char,int> map;
        unordered_map<string,int> map1;
        for(int i=0;i<s.size();i++)
        {
            map[s[i]]++;
            if(i-start+1>minSize)
            {
                if(--map[s[start]]==0)map.erase(s[start]);
                start++;
            }
            if(i-start+1==minSize && map.size()<=maxLetters)
                ans=max(ans,++map1[s.substr(start,i-start+1)]);
        }
        return ans;
    }
};
