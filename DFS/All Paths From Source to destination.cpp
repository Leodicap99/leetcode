class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<vector<int>>& graph,int src,int dst,vector<int> path)
    {
        path.push_back(src);
        if(src==dst)
        {
            ans.push_back(path);
            return;
        }
        for(auto x:graph[src])
        {
            helper(graph,x,dst,path);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==0)return ans;
        vector<int> path;
        helper(graph,0,n-1,path);
        return ans;
    }
};
