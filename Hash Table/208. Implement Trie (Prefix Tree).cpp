class Trie {
public:
    unordered_set<string> s;
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        s.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(s.find(word)==s.end())return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(s.size()==0)return false;
        for(auto it=s.begin();it!=s.end();it++)
        {
            string str=*it;
            bool ans=true;
            if(prefix.size()>str.size())continue;
            for(int i=0;i<prefix.size();i++)
            {
                if(prefix[i]!=str[i])ans= false;;
            }
            if(ans)return true;
        }
        return false;
    }
};
