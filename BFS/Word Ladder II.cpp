class Solution {
public:
    vector<vector<string>> findLadders(string b, string e, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_map<string,int> map;
        for(string w:wordList)map.insert({w,INT_MAX});
        queue<pair<string,vector<string>>> q;
        q.push({b,{b}});
        map[b]=0;
        while(!q.empty())
        {
            auto n=q.front();
            q.pop();
            string s=n.first;
            auto x=n.second;
            if(s==e)
            {
                ans.push_back(x);
                continue;
            }
            for(int i=0;i<s.size();i++)
            {
                char ch=s[i];
                for(char c='a';c<='z';c++)
                {
                    s[i]=c;
                    if(map.find(s)==map.end())continue;
                    if(map[s]<x.size())continue;
                    map[s]=x.size();
                    x.push_back(s);
                    q.push({s,x});
                    x.pop_back();
                }
                s[i]=ch;
            }
        }
        return ans;
    }
};
