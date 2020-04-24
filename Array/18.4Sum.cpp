This is similar to 2 sum 3 sum etc. Here we try to mimic 2sum by mapipulating some data.
Lets take an example with some duplicates as we can tackle edge cases with these.

nums = [3,2,3,3,4,6,7,10] target = 11

first as we did in 2 sum we ll have to sort the array so we can use two pointer method efficiently and accurately.
 
nums = [2,3,3,3,4,6,7,10]
as we be needing 4 pointers first we will be initializing two fixed pointer at index 0 and 1

nums = [2,3,3,3,4,6,7,10]
        ^ ^
        | |
        i j
here a proble arises since i have multiple 3s, i might get duplicate values in my final answer.
so we keep increment j until it reaches 4.Why not 3? Thats because according to my code i will take care of that.
 
nums = [2,3,3,3,4,6,7,10]
        ^       ^
        |       |
        i       j
Now we want to perform the 2sum. So what we do is subtract  nums[i]+nums[j] from the target. So if we subtract the 2 values it becomes a 2sum.
l=j+1,r=nums.size()-1

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(nums.size()<=2)return ans;
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(j!=i+1 && nums[j]==nums[j-1])continue;
                int left=j+1,right=nums.size()-1;
                int sum=target-nums[i]-nums[j];
                while(left<right)
                {
                    if(nums[left]+nums[right]==sum)
                    {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++,right--;
                        while(left<right && nums[left]==nums[left-1])left++;
                        while(left<right && nums[right]==nums[right+1])right--;
                    }
                    else
                    {
                        if(nums[left]+nums[right]<sum)left++;
                        else right--;
                    }
                }
            }
        }
        return ans;
    } 