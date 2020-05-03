    int numberOfSubarrays(vector<int>& nums, int k) {
       for(int &x:nums)
           x=x%2;
        unordered_map<int,int> map;
        map[0]=1;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(map.find(sum-k)!=map.end())
                ans+=map[sum-k];
            map[sum]++;
        }
        return ans;
    }
