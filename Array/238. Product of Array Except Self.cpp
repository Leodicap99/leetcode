/*
THIS SOLUTION USES EXTRA SPACE
Because we are not allowed to use division operation we will be adopting this approach:

Input:  [1,2,3,4]

Let the left array be calculated by by using the prefix sum algorith but by multiplying instead of adding:
left[0] = 1
left =[1,1*1,1*1*2,1*1*2*3]
      [1,1,2,6] <-----Notice that we have ignored the last array element will lead to duplication.

      left[i] = left[i-1]*array[i-1]

Let right[n-1] = 1

right = [2*3*4*1,3*4*1,4*1,1]
        [24,12,4,1]   <-----Notice that we ignored the first array element

     right[i] = right[i+1]*array[i+1]

 ans[i]=left[i]*right[i]


 Intuition beind using the left and right prfix multiplication array:

 left = [1,arr[0],arr[0]*arr[1],arr[0]*arr[1]*arr[2]]
 right= [arr[3]*arr[2]*arr[1],arr[2]*arr[1],arr[1],1]
 so if we see here we tried the to multiply in such a way that the last of left array will have n-2 elements multiplied same with 0 
 and the rest of the elements if the left array will have (n-1)/2 elements and the right will have the other half.
*/
     vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==0)return ans;
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        left[0]=1,right[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++)
            left[i]=nums[i-1]*left[i-1];
        for(int i=nums.size()-2;i>=0;i--)
            right[i]=nums[i+1]*right[i+1];
        for(int i=0;i<nums.size();i++)
           ans.push_back(left[i]*right[i]);
        return ans;
    }