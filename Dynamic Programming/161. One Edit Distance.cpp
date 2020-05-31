/*
Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

    Insert a character into s to get t
    Delete a character from s to get t
    Replace a character of s to get t

*/
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n=s.size(),m=t.size();
        if(n>m)return isOneEditDistance(t,s);
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                if(m==n)return s.substr(i+1)==t.substr(i+1);
                else return s.substr(i)==t.substr(i+1);
            }
        }
        return n+1==m;
    }
};
