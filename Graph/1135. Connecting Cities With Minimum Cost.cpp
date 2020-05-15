    /*
    This is a typical Prims algorithm problem. I use a binary heap to solve this problem
    Time complexity:- O((E+V)LOGV)
    */
    int minimumCost(int N, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> graph(N+1);
        for(auto &x:connections)                            //Building graph
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        vector<bool> vis(N+1,false);                       //Keep track of the visited cities
        vector<int> min_cost(N+1,INT_MAX);                 //Keep track of the minimum cost of the cities
        auto cmp=[](const pair<int,int> &a,const pair<int,int> &b)
        {
            return a.second>b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);   //Min heap according to the weight of the edges
        pq.push({1,0});   //We start from node 1 giving it an initial cost as 0
        int count=0,ans=0;
        while(!pq.empty()&&count!=N)
        {
            pair<int,int> p=pq.top();
            pq.pop();
            if(vis[p.first]==true)continue;   
            count++;                               //Keeping count of the cities as soon as count hits N we break from the loop
            vis[p.first]=true;                     //Keeping track of the visited cities
            ans+=p.second;
                for(auto &x:graph[p.first])
                {
                    if(!vis[x.first] &&x.second<min_city[x.first])     //If we find a city having its distance lesser than the one found in the min cost matrix we push into the heap
                    {
                         pq.push({x.first,x.second});
                        min_city[x.first]=x.second;
                    }
                }
               
        }
        return count==N?ans:-1;    //If count is not equal to 0 then we havent met all the cities yet 
    }