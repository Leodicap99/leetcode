/*
The way to solve this question is first build a graph:-
        vector<vector<int>> graph(n);
        int ans=0;                                        //I use an adjacency list u can use whatever u want
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
 After building a graph our main focus is to vist all the neighbours of all the nodes in the graph and more importantly to not visit them multiple
 times.
 We can do this by doing a dfs and a bool matrix which keeps tracks of the visited nodes so that we donot visit them again:-
*/
     void dfs(vector<vector<int>> &graph,vector<bool> &vis,int i)
    {
        if(vis[i])return;
        vis[i]=true;
        for(auto x:graph[i])
            dfs(graph,vis,x);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int ans=0;
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(graph,vis,i);
            }
        }
        return ans;
    }