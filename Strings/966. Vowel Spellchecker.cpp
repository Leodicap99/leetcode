class Solution {
public:
    string lower(string s)
    {
        string t;
        for(char ch:s)t+=tolower(ch);
        return t;
    }
    string devowel(string s)
    {
        s=lower(s);
        for(char &ch:s)
        {
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')ch='*';
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> set(wordlist.begin(),wordlist.end());
        unordered_map<string,string> map1,map2;
        for(string s:wordlist)
        {
            string low=lower(s),nvowel=devowel(s);
            map1.insert({low,s});
            map2.insert({nvowel,s});
        }
        for(string &s:queries)
        {
            if(set.find(s)!=set.end())continue;
            string low=lower(s),nvowel=devowel(s);
            if(map1.count(low))s=map1[low];
            else if(map2.count(nvowel))s=map2[nvowel];
            else s="";
        }
        return queries;
    }
};
