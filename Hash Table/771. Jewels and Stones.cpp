/*
We use a hashset to solve it
Space complexity = O(n)
Time complexity = O(n)
*/
    int numJewelsInStones(string J, string S) {
        int ans=0;
        unordered_set<char> s(J.begin(),J.end());
        for(int i=0;i<S.size();i++)
        {
            if(s.find(S[i])!=s.end())ans++;
        }
        return ans;
    }