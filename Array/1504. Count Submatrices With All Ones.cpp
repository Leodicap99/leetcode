class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> prefix(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(!mat[i][j])continue;
                if(j!=m-1)
                prefix[i][j]+=prefix[i][j+1];
                prefix[i][j]+=mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=INT_MAX;
                for(int k=i;k<n;k++)
                {
                    x=min(x,prefix[k][j]);
                    ans+=x;
                }
            }
        }
        return ans;
    }
};
