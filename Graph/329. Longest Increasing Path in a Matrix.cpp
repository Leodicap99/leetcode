class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return 0;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> indegree(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(auto &x:dir)
                {
                    int nx=i+x[0];
                    int ny=j+x[1];
                    if(nx>=0 && ny>=0 && nx<n && ny<m)
                    {
                        if(matrix[nx][ny]>matrix[i][j])
                            indegree[i][j]++;
                    }
                }
            }
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(indegree[i][j]==0)q.push({i,j});
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(auto &x:dir)
                {
                    int nx=p.first+x[0];
                    int ny=p.second+x[1];
                    if(nx>=0 && ny>=0 && nx<n &&ny<m )
                    {
                        if(matrix[nx][ny]<matrix[p.first][p.second]&& --indegree[nx][ny]==0)
                            q.push({nx,ny});
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};
