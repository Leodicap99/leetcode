/*
This problem can be efficiently solved by Union Find.
Note that I am not using the path compression method!

Firstly we create a groups array which denotes that every alphabet is a parent to itself
The way to group(Union) the alphabets is such that if 2 alphabets have the different parents we make the bigger(lexographically) alphabets parent as the smaller one.
*/
    int find(int x,vector<int> &parent)
    {
        return parent[x]==x?x:find(parent[x],parent);
    }
    string smallestEquivalentString(string A, string B, string S) {
        string ans;
        vector<int> groups(26);
        for(int i=0;i<26;i++)groups[i]=i;
        for(int i=0;i<A.length();i++)
        {
            int group1=find(A[i]-'a',groups);
            int group2=find(B[i]-'a',groups);
            if(group1!=group2)
            {
                groups[max(group1,group2)]=min(group1,group2);
            }
        }
        for(int i=0;i<S.size();i++)
        {
            ans+=find(S[i]-'a',groups)+'a';
        }
        return ans;
    }