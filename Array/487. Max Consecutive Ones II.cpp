    int findMaxConsecutiveOnes(vector<int>& nums) {
                int ans = 0, count = 0, index = -1;
        for(int i = 0;i< nums.size(); i++){
            if(nums[i] == 1){
                count++;
            }else{
                count = i - index;
                index = i;
            }
            ans = max(ans,count);
        }
        return ans;
    }
