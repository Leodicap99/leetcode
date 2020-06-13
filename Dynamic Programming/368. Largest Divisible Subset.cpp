class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> t(nums.size());
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && t[j].size()>t[i].size())
                    t[i]=t[j];
            }
            t[i].push_back(nums[i]);
            if(ans.size()<t[i].size())ans=t[i];
        }
        return ans;
    }
};
