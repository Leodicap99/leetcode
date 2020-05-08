/*
The way we are going to tackle this problem is by first checking each substring is present in the dictionary or not.
We should make sure no substring overlap occurs thats why we will be using dp here.
We also have to make sure if the full string is partioned or not.
*/
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());   //This will be used to check if a substring is present in the set or not
        vector<int> dp(s.size()+1,false);
        dp[0]=true;                                                   //We use true o tell that the substrng iverlap wont happen if u strat from here.
        for(int i=1;i<=s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j] && st.find(s.substr(j,i-j))!=st.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
/*
Lets test the code with an example
Note that the question asks whether the string is partioned or not so whther the all the elements in wordDict is used or not is not our concern

s = "catsandog"   wordDict = ["cats", "dog", "sand", "and", "cat"]


           c     a    t     s     a     n     d     o      g
dp [true,false,false,false,false,false false false,false,false]

dp of 0 says that a substring can be started from the jth index of the string 

the for loop i goes till a where s.substr(j,i-j) gives us cats which is present so we put i which is 5 becomes true;

           c     a    t     s     a     n     d     o      g
dp [true,false,false,false,false,true false false,false,false]

then when i equals 8  if(dp[j] && st.find(s.substr(j,i-j))!=st.end()) satisfies when j hits 5
as and is present we put dp[i]=true.

           c     a    t     s     a     n     d     o      g
dp [true,false,false,false,false,true false false,true,false]


Notice that the only word u are left to make is og which isnt present in the dictionary. so the last index will remain false
*/
