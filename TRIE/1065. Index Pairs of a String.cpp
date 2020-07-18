class Trie {
    public:
    bool end;
    Trie* children[26];
    Trie(){
        end=false;
        memset(children,NULL,sizeof(children));
    }
};
class Solution {
public:
    Trie* root=new Trie();
    void insert(string s)
    {
        Trie* node=root;
        for(char ch:s)
        {
            if(!node->children[ch-'a'])
                node->children[ch-'a']=new Trie();
            node=node->children[ch-'a'];
        }
        node->end=true;
    }
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        for(string str:words)
        {
            insert(str);
        }
        for(int i=0;i<text.size();i++)
        {
            Trie* node=root;
            for(int j=i;j<text.size();j++)
            {
                node=node->children[text[j]-'a'];
                if(!node)break;
                if(node->end)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
