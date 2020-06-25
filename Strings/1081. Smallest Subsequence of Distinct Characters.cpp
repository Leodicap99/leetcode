class Solution {
public:
    string smallestSubsequence(string text) {
        string ans;
        int last[26]={},seen[26]={};
        for(int i=0;i<text.size();i++)
            last[text[i]-'a']=i;
        for(int i=0;i<text.size();i++)
        {
            if(seen[text[i]-'a']++)continue;
            while(!ans.empty() && ans.back()>text[i] && i<last[ans.back()-'a'])
            {
                seen[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(text[i]);
        }
        return ans;
    }
};
