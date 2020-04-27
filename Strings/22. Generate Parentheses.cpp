/*
We will be attacking this problem using backtracking.
We will use a helper function called backtrack to hep us get to the desired solution.
Our main aim is to produce a parenthesis sequence which doesnt contain invalid sequence.Moreover we can restict the size of the sequences.
How?
If n=3 my string size would have to be 2* n(no less no more)because 3 opening braces and 3 closing braces.
How to track the number of opening braces and number of closing braces are equal?
We use an auxiliary variable say open that increments when string attaches '(' to it and decrements when the string attaches ')'
to it. thus if open ==0 and the size of the string is 2*n we have acheived a valid sequence.
*/
    void backtrack(int n,int i,int open,string s,vector<string> &ans)
    {
        if(open<0)return;                     //<-----checks for validity of the sequence
        if(i==n)
        {
            if(open==0)ans.push_back(s);      // <-----checks all the boxes so its a valid sequence.
            return;
        }
        backtrack(n,i+1,open+1,s+'(',ans);
        backtrack(n,i+1,open-1,s+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0)return ans;
        backtrack(2*n,0,0,"",ans); //<-------total string size must be 2*n n for opening braces + n for closing braces.
        return ans;
    } 