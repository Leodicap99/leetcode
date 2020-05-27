class Solution {
public:
    bool dfs(int i,vector<vector<int>> &graph,vector<int> &color,int c)
    {
        if(color[i]!=0)return color[i]==c;
        color[i]=c;
        for(auto &x:graph[i])
            if(!dfs(x,graph,color,-c))
                return false;
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(dislikes.size()==0)return true;
        if(n==1)return false;
        vector<vector<int>> graph(n+1);
        int cc=0;
        for(auto &x:dislikes)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> color(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==0 && !dfs(i,graph,color,1))
                return false;
        }
        return true;
    }
};
