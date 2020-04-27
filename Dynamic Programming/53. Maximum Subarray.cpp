/*
Our goal is to get the solution in o(n) time.
whenver we are traversing an array we have two options whether to include an element into the subarray or drop it.
Once an element is dropped a new subarray must begin because elements are coontiguos. We will need to simulataneously cache the elements
into out array.
*/
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int max_till_now=nums[0],max_ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            max_till_now=max(max_till_now+nums[i],nums[i]);
            max_ans=max(max_till_now,max_ans);
        }
        return max_ans;
    }