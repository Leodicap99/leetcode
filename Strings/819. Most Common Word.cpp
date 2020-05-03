/*
First we will preprocess the string in this way.
If i enounter an alphabet i will make it lowercase using tolower(c).
Otherwise i will replace that character with space(because string stream distinguishes words using spaces).
Then the rest is just hash map implementaton.
*/
    unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> map;
        for (auto & c: p) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(p);
        string w;
        int m=0;string ans;
         while(iss>>w)
         {
             if(ban.find(w)==ban.end())
             {
                 map[w]++;
                 if(map[w]>m)
                 {
                     m=map[w];
                     ans=w;
                 }
             }
         }
        return ans;
    }