class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=1;i<arr.size();i++)
            arr[i]^=arr[i-1];
        vector<int> ans;
        for(auto &x:queries)
            ans.push_back(x[0]==0?arr[x[1]]:(arr[x[1]]^arr[x[0]-1]));
        return ans;
    }
};
