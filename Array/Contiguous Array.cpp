class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_map<int,int> map;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]==0)?-1:1;
            if(sum==0)
                ans=i+1;
            if(!map.count(sum))
                map[sum]=i;
            if(map.count(sum))
            {
                ans=max(ans,i-map[sum]);
            }
        }
        return ans;
    }
};
