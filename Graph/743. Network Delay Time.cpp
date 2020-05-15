/*
The way to solve this by using Dijkstras algorithm
Dijkstras algorithm works on a directed graph without negative cycles.

The way we are going to solve this by using this algorithms is by first building a graph using the times array.
After the build we make use of priority queue to extract the smallest distance.
Then we perform our BFS using the priority queue which holds the starting node K and the distance which set as 0 first.

For every unvisited node we keep a count variable which keeps track of the number of nodes we visit.
Then we explore all of its unvisted neighbors and perform the same operations as before.
Note that when we exploring unvisited neighbors we push the current time + the neighbors time into it so as soon as count hits N we can
declare the second variable stored in the pq as our answer.
However if the count !=N we will return false as all the nodes ddnt send the signal.
*/
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(int i=0;i<times.size();i++)
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        auto cmp=[](const pair<int,int> &a,const pair<int,int> &b)
        {
            return a.second>b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        pq.push({K,0});
        int ans,count=0;
        vector<bool> vis(N+1,false);
        while(!pq.empty() &&count!=N)
        {
            pair<int,int> p=pq.top();
            pq.pop();
            if(vis[p.first]==false)count++;
            vis[p.first]=true;
            ans=p.second;
            if(graph.count(p.first))
            {
                for(auto &x:graph[p.first])
                {
                    if(!vis[x.first])
                        pq.push({x.first,x.second+p.second});
                }
            }
        }
        return count==N?ans:-1;
    }