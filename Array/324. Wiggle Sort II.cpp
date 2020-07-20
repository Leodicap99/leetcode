/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].

Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums.begin(),nums.end());
        sort(sorted.begin(),sorted.end());
        for(int i=nums.size()-1,j=0,k=i/2+1;i>=0;i--)
        {
            nums[i]=sorted[i&1?k++:j++];
        }
    }
};

/*
It is actually very smart to reverse the halves. Consider the case SMML, the result is
M S
L M

MLSM

If we don't reverse the halves, the result would be
S M
M L

SMML
which is wrong
*/
