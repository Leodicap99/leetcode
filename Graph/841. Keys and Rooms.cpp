    unordered_map<int,vector<int>> graph;
    vector<bool> vis;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vis.resize(n,false);
        for(int i=0;i<rooms.size();i++)
        {
            for(auto &x:rooms[i])
                graph[i].push_back(x);
        }
        queue<int> q;
        q.push(0);
        int count=0;
        while(!q.empty() && count!=n)
        {
            int t=q.front();
            q.pop();
            if(vis[t]==false)count++;
            vis[t]=true;
            if(graph[t].size())
            {
                for(auto &x:graph[t])
                {
                    if(!vis[x])q.push(x);
                }
            }
        }
        return count==n;
    }
