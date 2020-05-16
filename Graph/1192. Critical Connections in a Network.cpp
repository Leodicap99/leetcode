The problem simply asks us to find the bridges in the graph.
Lets take an example of the following graph:-

   0------1 
   |       \ 
   |        \
   |         \
   |          \
   5----3-------2
        |
        |
        4

A bridge is simply an edge in an undirected connected graph reoving which disconnects the graph.
To find all the bridges in the graph we perform a dfs to visit each node.
While we visit each node we assign two values to it id number and lowlink number.

Id number - Denotes the time at which the node is visited.
Lowlink number - Denotes whether there is other early node(based on id number) that can be visited by that node.



(id=1,
 lowlink=1)
   |       
   0------1  
   |       \ 
   |        \
   |         \
   |          \
   5----3-------2
        |
        |
        4

(id=1,
 lowlink=1)
   |       
   0------1  <----(id=2,lowlink=2)
   |       \ 
   |        \
   |         \
   |          \
   5----3-------2
        |
        |
        4

 (id=1,
 lowlink=1)
   |       
   0------1  <----(id=2,lowlink=2)
   |       \ 
   |        \
   |         \
   |          \
   5----3-------2 <----(id=3,lowlink=3)
        |
        |
        4

 (id=1,
 lowlink=1)
   |       
   0------1  <----(id=2,lowlink=2)
   |       \ 
   |        \
   |         \
   |(id=4,ll=4)\
   5----3-------2 <----(id=3,lowlink=3)
        |
        |
        4


   (id=1,
 lowlink=1)
   |       
   0------1  <----(id=2,lowlink=2)
   |       \ 
   |        \
   |         \
   |(id=4,ll=4)\
   5----3-------2 <----(id=3,lowlink=3)
        |
        |
        4
        |
   (id=5,lowlink=5)  

Since there are no unvisited nodes to node 4 we have to check 2 things while cosidering 3(parent) and 4(node):-

1. Compare the lowlink values of 3 and 4 and assign the minimum value to 3(Since the low value of 3 and 4 minimum is 3 we dont do anything).

Why did we do this?
We needed to compare the lowlink values of both nodes to update the information of nodes 3s connectivity to the earliest node possible.

2. We compare the lowlink value of 4 and id value of 3.This will decide whether this edge is a bridge or not.
As the id value of 3 is lesser than the lowlink value of 4 we can safely say that node 4 has no connections with nodes which where made at earlier time.
Thus 3-4 is a bridge.

Note that 1 and 2 are if else cases if low[node]<=low[neighbor] then perform 1
else perform 2

                             (id=1,
                              lowlink=1)
                                 |       
                                 0------1  <----(id=2,lowlink=2)
                                 |       \ 
                                 |        \
                                 |         \
                                 |(id=4,ll=4)\
          (id=6,lowlink=6)--->   5----3-------2 <----(id=3,lowlink=3)
                                      |
                                      |
                                      4
                                      |
                            (id=5,lowlink=5)  

Then perform the same operations with the other nodes.



class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> graph;
    vector<int> id;
    vector<int> lowlink;
    vector<bool> vis;
    int time=0;
    void dfs(int node,int parent)
    {
        id[node]=lowlink[node]=time++;
        vis[node]=true;
        for(int &x:graph[node])
        {
            if(parent==x)continue;
            if(vis[x]==false)
            {
                dfs(x,node);
                lowlink[node]=min(lowlink[node],lowlink[x]);
                if(id[node]<lowlink[x])
                    ans.push_back({node,x});
            }
            else 
                lowlink[node]=min(lowlink[node],id[x]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        vis.resize(n,false);
        lowlink.resize(n,0);
        id.resize(n,0);
        for(auto &x:connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
                dfs(i,i);
        }
        return ans;
    }
};