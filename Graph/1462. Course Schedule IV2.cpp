class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<vector<int>> graph(n,vector<int>(n,INT_MAX/2));
        for(int i=0;i<p.size();i++)
        {
            graph[p[i][0]][p[i][1]]=1;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(graph[i][j]>graph[i][k]+graph[k][j])
                        graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
        vector<bool> ans;
        for(int i=0;i<q.size();i++)
        {
            if(graph[q[i][0]][q[i][1]]!=INT_MAX/2)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};1462. Course Schedule IV
