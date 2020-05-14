/*
I used two vectors of size 26.
The first vector lets say map1 stores the frequency of characters in s1
The second vector lets say map2 stores the frequency of characters in s2 as soon as i>=s1.size() we decrement the frequency fo the character presnt in i-s1.size() location
*/
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        int l=s1.size();
        vector<int> map1(26),map2(26);
        for(char &ch:s1)map1[ch-'a']++;
        for(int i=0;i<s2.size();i++)
        {
            map2[s2[i]-'a']++;
            if(i>=l)map2[s2[i-l]-'a']--;
            if(map1==map2)return true;
        }
        return false;
    }