/*
We will be adopting depth first search approach here.
For each number in digits we will plunge thru all the possible combinations with other digits.
We invoke a dfs function which will help us get all the possible combinations of digits int ans(vector<string>)

First keep a dictionary(hash table) that will map each digit to its combiations.
dfs will function will hold the digits array, an index, a temporary string and ans.
If the index reaches digits.size() we push the string we got into ans.
if not we will first invoke the first digits mapped string(eg "2"->"abc").
Then will take the first digit and do a depth first search.
Let me demonstrate:
"23"
"2" -> "abc"
we will do a dfs on a first.

     |    |
     | a  |  <-----recursion stack (This will help us to backtrack).
     |____|

we increment the index which becomes 1 the temp string(which was intially empty) holds "a".
Since index < digits.size() we proceed by getting the mapped string of "3" -> "def".

we push d into the stack first and recurse by incrementing index and temporary string ="ad".

     | d  |
     | a  |  <-----recursion stack (d is pushed in).
     |____|

As index==dogots.size() we push the final string("ad") to ans.
Then we return to the call stack which pops out d.
Since we have visited d we move to e and perform the same operations. As it is repetitive i ll just be showing the diagrams.

     |    |
     | e  |
     | a  |  <-----recursion stack (d is popped and e is pushed).
     |____|

      ans=[{"ad"},{"ae"}]

     |    |
     | f  |
     | a  |  <-----recursion stack (e is popped and dis pushed in).
     |____|

     ans=[{"ad"},{"ae"}{"af"}]

     Now after popping out a is also popped out and b is pushed in 

     |    |
     | b  |  <-----recursion stack (both a and f are popped out).
     |____|
     Same procedure will continue and thus u have got all the combinations.
*/
    string dict[10]={{""},{""},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}}; 
    void dfs(string &digits,int index,string s,vector<string> &ans)
    {
        if(index==digits.size())
        {
            ans.push_back(s);
            return;
        }
        string temp=dict[digits[index]-'0'];
        for(int i=0;i<temp.size();i++)
            dfs(digits,index+1,s+temp[i],ans);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)return ans;
        dfs(digits,0,"",ans);
        return ans;
    }