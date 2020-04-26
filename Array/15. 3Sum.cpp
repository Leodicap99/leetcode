/*
What we try to do here is try to mimic 2Sum by doing some more extra steps.
Those are:
1. We have to account for the fact that no duplicates are allowed.
2. We have to make sure our main loop runs from 0 to n-3 becuase then your left poinetr and right pointer will hold invalid indices 
We proceed our main loop normally from 1 to n-3.
We keep our left pointer at i+1 and right pointer at n-1.

To avoid duplications in our main loop we will have an if statement saying if(i!=0 and nums[i]!=nums[i+1])continue.
Which means example Im having nums = [1,1,1,2,5,.....] here our first 1 will enter the loop ignoring the if condition
however the 2nd and 3rd ones will be skipped to avoid duplication of data.

Another thing we have to account for is wen we find the sum==0 we check for removing duplications by using a while loop stating
while(l<r && nums[l]==nums[l-1])l++; and while(l<r && nums[r]==nums[r+1])r--;

By doing this we have eliminated all the possible duplications that can be caused!
*/

   vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<=2)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i!=0&&nums[i]==nums[i-1])continue;
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1])l++;
                    while(l<r &&nums[r]==nums[r+1])r--;
                }
                else if(sum<0)l++;
                else
                    r--;
            }
        }
        return ans;
    } 