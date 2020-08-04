class Solution {
public:
    int zeroes(vector<int> &v)
    {
        int ans=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i])break;
            ans++;
        }
        return ans;
    }
    vector<int> grid_to_vec(vector<vector<int>> grid)
    {
        vector<int> ans;
        for(auto &x:grid)
        {
            ans.push_back(zeroes(x));
        }
        return ans;
    }
    int helper(vector<int> &v)
    {
        int n=v.size(),ans=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<n-i-1)
            {
                int j=i;
                while(j<n && v[j]<n-i-1)j++;
                if(j==n)return -1;
                while(j>i)
                {
                    swap(v[j],v[j-1]);
                    ans++;
                    j--;
                }
            }
        }
        return ans;
    }
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> a=grid_to_vec(grid);
        return helper(a);
    }
};
