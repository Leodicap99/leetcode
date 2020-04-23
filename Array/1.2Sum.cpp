/*
The approach i will be taking is a two pointer method as it will be very easy to understand.
Lets take this array as ana example
Given nums = [2, 7, 11, 15], target = 9;
what we ll do is keep a pointer lets say l(denoting left pointer) that points to leftmost index (ie.0) and r(denoting right pointer) that points to the rightmost index (ie nums.size()-1).
l(left pointer)                
 |
  v
[2, 7, 11, 15]                   ----------> This is how we denote the pointers initially.
            ^
            |
            (right pointer)
Now our target is 9 but here nums[l]+nums[r]=17 which is greater than 15, So our intuition will be to move one of the pointers to get a different sum right?You are absolutely right! But which pointer? If we move the left pointer we ll get a sum greater...
    l(left pointer)                
    |
    v
[2, 7, 11, 15]                   ----------> This is how we denote the pointers .
            ^
            |
       (right pointer)
here the sum=nums[l]+nums[r]=21 which is greater so moving the left pointer wouldnt make sense;
hence we ll try to move the right pointer;
l(left pointer)                
|
v
[2, 7, 11, 15]                   ----------> This is how we denote the pointers .
        ^
        |
    (right pointer)
 sum=nums[l]+nums[r]=13 We are approaching closer to the target!
 Again we ll try our trial and error method. Lets try moving the left pointer and see what happens.
     l(left pointer)                
    |
    v
[2, 7, 11, 15]                   ----------> This is how we denote the pointers .
        ^
        |
   (right pointer) 
   This gives us the sum of 19 again not closer; then we move the right pointer again.
l(left pointer)                
|
v
[2, 7, 11, 15]                   ----------> This is how we denote the pointers .
    ^
    |
(right pointer) 
thus the sum here is 9!
LETS TRY DERIVING A FORMULA FOR THIS.
if(nums[l]+nums[r]==target)we have got the answer!
else if(nums[l]+nums[r]<target)we move the pointer which has a smaller value to a greater value which is left pointer.
else if(nums[l]+nums[r]>target)we move the pointer which is the greater value to the left which is the right pointer.
But this all makes sense if l always points to the next smaller element and right to the next greater element right?
thus we sort the array
*/
vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<int> v=nums;//we use a copy vector to get the indices of our answer
        sort(nums.begin(),nums.end());
        vector<int> ans;
        while(l<r)
        {
        	if(nums[l]+nums[r]==target)break;
        	else if(nums[l]+nums[r]>target)r--;
        	else
        	l++;
        }
        for(int i=0;i<v.size();i++)
        {
        	if(v[i]==nums[l]||v[i]==nums[r])
        	ans.push_back(i);
        }
        sort(ans.begin(),ans.end());//we sort it so that the first index comes firs ie. nums[l] not nessarily have to come before nums[r];
        return ans;
    }
