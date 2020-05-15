/*
Prims algorithm will greedily find the shortest path connecting all nodes.
But why do we need all the nodes?
Because in the question there is an extra paameter with k stops. Using that information we can check all the best possibilities and find a solution
to cater the input given.
*/
class Solution {
public:
    
struct cmp {
bool operator()(const vector<int> &a, const vector<int> &b) {
return a[1] > b[1];                          //Return the lesser distanc of the 2.
}                                            //Remember preiority queue is maxheap by default
};
    
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;      //We use a minheap to select the minimum distance
    vector<pair<int,int>> adj[n];
    for (int i=0;i<flights.size();i++) {
    adj[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));   //Our adjacency list consists of sorce,destination,distance
    }

    for(int i=0;i<adj[src].size();i++) {
           vector<int> vec({adj[src][i].first, adj[src][i].second, 0});      //Our priority queue consists of destination,distance,no of stops
           pq.push(vec);
    }
    if(pq.empty())                                        //If pq is empty there are no routes from souce thus return -1
            return -1;
    
    while (!pq.empty())
    {
        vector<int> p = pq.top();
        pq.pop();
       
        if (p[2] > K)    //If the number of stops is greater than k we just pop the element and analyze the next element
             continue;
        if(p[0] == dst)  //If the destination is reached we just return the distance calculated thus far
            return p[1];
        
        for(int i=0;i<adj[p[0]].size();i++) {
              vector<int> vec({adj[p[0]][i].first, adj[p[0]][i].second + p[1], p[2] + 1});  //We add the currnt distance to the previous calculated one and increment the number of stops
            pq.push(vec);
        }
        
    }
    return -1;
}

};