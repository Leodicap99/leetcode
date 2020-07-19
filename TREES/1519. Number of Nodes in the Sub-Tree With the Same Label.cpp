class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> count;
    vector<int> ans;
    void dfs(int i,string &labels,int prev)
    {
        if(graph[i].size()==0)
        {
            ans[i]=1;
            return;
        }
        for(auto &x:graph[i])
        {
            if(x==prev)continue;
            dfs(x,labels,i);
            for(int j=0;j<26;j++)
                count[i][j]+=count[x][j];
        }
        ans[i]=count[i][labels[i]-'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        graph.resize(n);
        count.resize(n,vector<int>(26));
        ans.resize(n);
        for(auto &x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++)
        {
            count[i][labels[i]-'a']=1;
        }
        dfs(0,labels,-1);
        return ans;
    }
};
