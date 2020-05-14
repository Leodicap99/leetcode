    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char> map;
        for(int i=0;i<order.size();i++)
            map[order[i]]=(char)('a'+i);
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            string t,s=words[i];
            for(int j=0;j<s.size();j++)
                t+=map[s[j]];
            ans.push_back(t);
        }
        return is_sorted(ans.begin(),ans.end());
    }
