/*
All we have to do in this problem is to go down up down up...
we maintain a bool variable that flips its states once i is at 0 or at numRows-1.
We simulatneously add to vector array conatining string and later tranfer it to a string.
We are mimicing the question as it is.

s = "PAYPALISHIRING", numRows = 3
Lets maintain a vector<string> of size numRows.
Let my bool variable say goingdown=false initially.
we add 'P' to the first row.
we add 'A' to the second row.
we add 'Y' to the third row.
as we reached the end of the row we flip the state of goingdown. So no we move up.
[P]
[AP]
[Y]
We go to the 1st row 
[PA]
[AP]
[Y]
now as we reached 0th row we flip the state of goingdown(ie goingdown = true).
[PA]
[APL]
[Y]
if we continuously do this we reach the final desired state 
[PAHN]
[APLSIIG]
[YIR]
Now we use an auxiliary string that adds the string row wise yielding the final answer.
*/
   string convert(string s, int numRows) {
        if(s.size()==0)return s;
        if(numRows==1)return s;
       vector<string> ans(min(numRows, int(s.size())));
        int curr=0;
        bool goingdown=false;
        for(char &ch:s)
        {
            ans[curr]+=ch;
            if(curr==0||curr==numRows-1)goingdown=!goingdown;
            curr+=(goingdown)?1:-1;
        }
        string res="";
        for(string &s1:ans)res+=s1;
        return res;
    }
