/*
To visit a node from a parent the cost is 2. Because I visit the node and backtrack which is considered to the cost.

I have to count only the cost of collecting the apples present in the nodes and not count unnecessary nodes.
How do we do that?

We use a dfs finction to help us with that.
We have 5 parameters
1. A build graph adjacncy list
2. A vector bool array to help us not visit a node multiple times
3. A node which is passed as 0 initially.
4. Cost variable which will be 2 more that the previous one because of the fact i told about earlier
5. hasApple array.

The dfs will help us with finding the cost by the following method:-

1. If I find out that atleast one of my children have nodes i return the cost and the children cost to the call stack.
2. If I find out that none of the children contains apples we return 0.
*/
    vector<bool> vis;
    int dfs(vector<vector<int>> &graph,vector<bool>& hasApple,int node,int cost)
    {
        if(vis[node])return 0;
        vis[node]=true;
        int children_cost=0;
        for(auto x:graph[node])
            children_cost+=dfs(graph,hasApple,x,2);
        if(children_cost==0 && hasApple[node]==false)return 0;
        return (children_cost+cost);
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        vis=vector<bool>(n,false);
        for(auto &x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        return dfs(graph,hasApple,0,0);
    }