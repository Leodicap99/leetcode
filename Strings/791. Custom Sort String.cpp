We use STL to custom sort the string.
    string customSortString(string S, string T) {
        unordered_map<char,int> map;
        for(int i=0;i<S.size();i++)
        {
            map[S[i]]=i+1;
        }
        sort(T.begin(),T.end(),[&](char a,char b)
             {
                 return map[a]<map[b];
             });
            return T;
    }