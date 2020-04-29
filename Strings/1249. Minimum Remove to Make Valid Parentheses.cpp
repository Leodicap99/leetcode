/*
The way to tackle this question is to keep a varial lets say open that increments for every opening braces and decrements for every closing
braces.
We will first be considering mismatches of the closing brackets ')'.
if open is equal to 0 and a closing bracket occurs ignore it.
s = "lee(t(c)o)de)"    open=0
         ^
         |
         i
open = 1
s = "lee(t(c)o)de)"
          ^
          |
          i 
open = 2

s = "lee(t(c)o)de)"
            ^
            |
            i
open is not 0 
open = 1

s = "lee(t(c)o)de)"
              ^
              |
              i 
open not 0 
open = 0

s = "lee(t(c)o)de)"
                 ^
                 |
                 i 
open is 0 so ignore

But what if there are more opening braces than closing to handle this we first make sure the closing braces are taken care of
 then with the same open we start from behind and check if open is > 0 if so we skip it and decremnt open.
*/

     string minRemoveToMakeValid(string s) {
        int open=0;
        string t;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')open++;
            else if(s[i]==')')
            {
                if(open==0)continue;
                open--;
            }
            t+=s[i];
        }
        string ans;
        for(int i=t.size()-1;i>=0;i--)
        {
            if(t[i]=='(' && open>0)
            {
                open--;
                continue;
            }
            ans+=t[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    } 
