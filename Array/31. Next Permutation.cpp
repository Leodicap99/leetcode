    void nextPermutation(vector<int>& nums) {
        int k=nums.size()-2;
        while(k>=0 && nums[k]>=nums[k+1])k--; //we are trying to find a point were we can start performing a swap that is a swap with a bigger number and a smaller number.
        if(k==-1)
        {
            sort(nums.begin(),nums.end());  //if it is sorted in the reverse order the next permuation will rewind back to the first.
            return;
        }
        for(int i=nums.size()-1;i>k;i--)
        {
            if(nums[i]>nums[k])               //again we are trying to find a greater element present in the back to swap with a smaller element present in the front to get a greater array than the current one
            {
                swap(nums[i],nums[k]);
                break;
            }
        }
        reverse(nums.begin()+k+1,nums.end());   //we reverse it becuase we have to get the permutation which is just greater than the current one.
    }