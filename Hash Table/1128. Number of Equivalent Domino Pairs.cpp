/*
We store the pair into hashmap and increment it wheever we encounter this.
How do we store the pair?
Let the pair be {a,b} where a store the minimum of the 2 and b stores the maximum of the two.

Once we iterate through the map we our count value will not store n or n-1 nut will store this
if n=it->second-1
count+=(n)*(n+1)/2 why?
because dominoes matching occurs for every domino after it so for example

[1,2][1,2][1,2][1,2][2,1][2,1]

here map[{1,2}] = 6
but for the first 1,2 5 are matched with it
for second 1,2 4 are matched with it
Thus n,n-1,n-2,,,,1 = n*(n+1)/2 (Sum of natural numbers upto n)
*/
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> map;
        for(int i=0;i<dominoes.size();i++)
        {
            int a=min(dominoes[i][0],dominoes[i][1]),b=max(dominoes[i][0],dominoes[i][1]);
            map[{a,b}]++;
        }
        int count=0;
        for(auto it=map.begin();it!=map.end();it++)
        {
            if(it->second>1)
            {
                int n=it->second-1;
                count+=(n)*(n+1)/2;
            }
        }
        return count;
    }