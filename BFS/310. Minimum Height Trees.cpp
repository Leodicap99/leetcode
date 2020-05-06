/*
I have got the idea how to solve using this post.
https://leetcode.com/problems/minimum-height-trees/discuss/599934/C%2B%2B-O(n)-time-and-O(n)-Using-BFS-Easy-to-Understand
The main idea of this algorithm is to keep trimmin the graphs until there are 2 nodes in the graph.
Why 2 nodes?
There are a maximum of 2 nodes that can contribute to minimum height tree.

A degree of node is basically the number of edges connected to for from the node. This is the case for an undirected graph.

     0  1  2
      \ | /
        3
        |
        4
        |
        5 
the degres for the following nodes are

0 - 1
1 - 1
2 - 1
3 - 2
4 - 2
5 - 1

We are going to keep trimming the leafs(nodes with degree=1) until there are 2 nodes
*/
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> graph[n],degree(n,0);
        for(auto x:edges)
        {
            graph[x[1]].push_back(x[0]);
            graph[x[0]].push_back(x[1]);
            degree[x[0]]++;
            degree[x[1]]++;                        //Updating the degrees of each nodes
        }
        int nodecount=n;
        while(nodecount>2)
        {
            queue<int> q;
            for(int i=0;i<n;i++)
            {
                if(degree[i]==1)
                {
                    q.push(i);
                    degree[i]=-1;
                nodecount--;                        //We decrement each time we visit a node with degree = 1
                }
            }
            while(!q.empty())
            {
                int t=q.front();
                q.pop();
                for(int x:graph[t])
                    degree[x]--;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==0||degree[i]==1)ans.push_back(i);     //If we are left with a node with degrees =0 or 1 that with contibute to an MHT
        }
        return ans;
    }