/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,int> indegree;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                char ch=words[i][j];
                indegree[ch]=0;
            }
        }
        unordered_map<char,unordered_set<char>> graph;
        for(int i=0;i<words.size()-1;i++)
        {
            string curr=words[i];
            string next=words[i+1];
            int n=min(curr.size(),next.size());
            for(int j=0;j<n;j++)
            {
                if(curr[j]!=next[j])
                {
                    unordered_set<char> s=graph[curr[j]];
                    if(s.find(next[j])==s.end())
                    {
                        graph[curr[j]].insert(next[j]);
                        indegree[next[j]]++;
                    }
                    break;
                }
                if(j==n-1 && curr.size()>next.size())return "";
            }
        }
        string ans;
        queue<char> q;
        for(auto it=indegree.begin();it!=indegree.end();it++)
        {
            if(it->second==0)q.push(it->first);
        }
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                char ch=q.front();
                q.pop();
                ans+=ch;
                for(auto &x:graph[ch])
                {
                    if(--indegree[x]==0)q.push(x);
                }
            }
        }
        return ans.size()==indegree.size()?ans:"";
    }
};
