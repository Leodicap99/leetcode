/*
Our main goal is to find abs(sum-target) to be as minimum as possible.
We first try to sort the array to make our queries more accurate and will be able to judge properly.
Now we make i to go from 0 to n-3 because above that left pointer will be holding invalid index.
We set our left pointer as i+1 and right pointer as nums.size()-1.
We keep checking for the minimum abs(sum-target) while simulatneously caching in the maximum in ans variable.

Let nums = [-1, 2, 1, -4], and target = 1 
We start traversing thru the array.
We perform sorting initially
Let us set the m that will be holding our abs(sum-target) initially to INT_MAX.

[-4, -1, 1, 2]
 ^   ^      ^
 |   |      |
 i   l      r

 nums[i] + nums[l] + nums[r] = sum 

 sum = -4 + -1 + 2  = -3
 m = |-3-1| = 4
 ans = sum = 3(because we will need to return the sum).

 since sum<target we move the left pointer.

 [-4, -1, 1, 2]
  ^       ^  ^
  |       |  |
  i       l  r

 sum = -4 + 1 + 2 = -1
 as m>|sum| we change m = 2
 ans = -1

 as it is lesser than the target we move the left pointer to the right l and r over laps so we break from the loop.

 [-4, -1, 1, 2]
       ^  ^  ^
       |  |  |
       i  l  r

sum = -1 + 1 + 2 = 2
 as m>|sum| we change m = 1
 ans = 2
*/
 This will be yielding our final answer as we have broken out of the loop.

     int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int m=INT_MAX,ans;
        for(int i=0;i<nums.size()-2;i++)
        {
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
            int sum=nums[l]+nums[r]+nums[i];
                if(m>abs(sum-target))
                {
                    m=abs(sum-target);
                    ans=sum;
                }
                else if(sum<target)l++;
                else r--;
            }
        }
        return ans;
    }