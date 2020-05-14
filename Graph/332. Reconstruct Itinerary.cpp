/*
This is the variation of dfs.
The way to tweak the dfs is to not to put a base condition and let the dfs fill and tsack and empty itslef
What i mean by this is 

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Lets say we built a graph of this and its adjacenecy list look like this:-
JFK - MUC
MUC - LHR
LHR - SFO
SFO - SJC

So when we perform a dfs on JFK

|        |
|        |
|        |   <-----Recursion Stack
|        |
|__JFK___|

We explore JFKs neighbors 

|        |
|        |
|        |
|  MUC   |
|__JFK___|

We explore Muc neighbors

|        |
|        |
|  LHR   |
|  MUC   |
|__JFK___|

|        |
|  SFO   |
|  LHR   |
|  MUC   |
|__JFK___|

|  SJC   |
|  SFO   |
|  LHR   |
|  MUC   |
|__JFK___|

Since SJC has no neighbors we pus it back to the answer

|        |
|  SFO   |      ans=SJC
|  LHR   |
|  MUC   |
|__JFK___|

|        |
|        |      ans=SJC,SFO
|  LHR   |
|  MUC   |
|__JFK___|

|        |
|        |      ans=SJC,SFO,LHR
|        |
|  MUC   |
|__JFK___|


|        |
|        |      ans=SJC,SFO,LHR,MUC 
|        |
|        |
|__JFK___|

|        |
|        |      ans=SJC,SFO,LHR,MUC,JFK 
|        |
|        |
|________|

We reverse the array and return it.
*/
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> map;  //We use priority queue for lexographic ordering
    vector<string> ans;
    void dfs(string s)
    {
        auto &x=map[s];
        while(!x.empty())
        {
            string to=x.top();
            x.pop();
            dfs(to);
        }
        cout<<s<<endl;
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &x:tickets)
            map[x[0]].push(x[1]);
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }

