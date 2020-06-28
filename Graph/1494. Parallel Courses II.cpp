class Solution {
public:using Graph = unordered_map<int, unordered_set<int>>;
    
    Graph buildGraph(vector<vector<int>>& dependencies, vector<int>& degree) {
        Graph graph;
        for (auto& relation : dependencies) {
            graph[relation[0]].insert(relation[1]);
            degree[relation[1]]++;
        }
        return graph;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& d, int k) {
        vector<int> indegree(n+1);
        Graph graph=buildGraph(d,indegree);
        queue<int> q;
        int semesters=0;
        for(int i=1;i<=n;i++)
            if(indegree[i]==0)q.push(i);
        while(!q.empty())
        {
            int size=q.size();
            semesters++;
            for(int i=0;i<k && i<size;i++)
            {
                int t=q.front();
                q.pop();
                for(auto &x:graph[t])
                {
                    if(--indegree[x]==0)q.push(x);
                }
            }
        }
        return semesters;
    }
};
