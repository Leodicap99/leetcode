/*
We will be using Common sense to solve this.
we take the first string as our answer initially.
we keep shrinking our answer for each iteration from 1 to n-1.

LET 
strs = ["flower","flow","flight"]
We initially put ans="flower"
then we start analyzing str[1]
if(s[i]!=ans[i])break
and update the ans to ans.substr(0,i) where i denotes the index at which  either both strings mismatched or reached the end of 1 of the strings.

So after analyzing strs[1] we we that i stops at 4 cuz we reached end of 1 string so ans = "flow" note that substr(i,j) means
substring from i to i+j and not to i+j+1!

In the next iteration we analyze strs[2].
After following the steps mentioned above u see i breaking out at 2 itself due to mismatch.
ans="fl" yielding our answer.
*/
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        string ans=strs[0];
        for(string &s:strs)
        {
            int i;
            for(i=0;i<s.size()&&i<ans.size();i++)
                if(s[i]!=ans[i])break;
            ans=s.substr(0,i);
        }
        return ans;
    }