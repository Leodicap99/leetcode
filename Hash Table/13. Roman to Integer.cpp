/*
We will be using hash tables to tackle this problem.
We store the integrs correspong to the roman numerals and cache in whenever we want to.
The only caviat u have to look forward is that when traversing through the string if s[i]<s[i+1].
Let s = "IX"
According to our brute force this would yield 10
So we traversing fromt back initially storing the last characters mapped value

So initially ans=10

We traverse backwards and check if (s[i]<s[i+1]) ans-=map[s[i]]

This gives us the final answer as 9.
*/
    int romanToInt(string s) {
       if(s.size()==0)return 0;
        unordered_map<char,int> map={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}};
        int ans=map[s[s.size()-1]];
        for(int i=s.size()-2;i>=0;i--)
        {
            if(map[s[i+1]]>map[s[i]])ans-=map[s[i]];
            else
                ans+=map[s[i]];
        }
        return ans;
    }