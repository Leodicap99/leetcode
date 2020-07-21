/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]


*/

class Solution {
public:
    string helper(long start,long end)
    {
        return start==end?to_string(start):to_string(start)+"->"+to_string(end);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        long prev=(long)lower-1;
        for(int i=0;i<=nums.size();i++)
        {
            long curr=(i==nums.size()?(long)upper+1:(long)nums[i]);
            if(curr-prev>=(long)2)
                ans.push_back(helper(prev+1,curr-1));
            prev=curr;
        }
        return ans;
    }
};
