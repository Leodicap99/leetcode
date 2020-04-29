/*
The way to be tackling the problem is to make all the elements from 1 to n wich are present in the array to be in their respective locations(ie i-1)
Like if we have the array [0,2,1]
we want nums[i] to be placed at i-1th location:
[1,2,0]
So to do this we will first traverse through the array and check if nums[i]=i+1 then we cana proceed if not swap it with the element
present at its location.
But a problem would arise due to this:
[7,8,9,11] there is no location 6 in this array thus throwing an error.
So lets revise our conditions
if nums[i]==i+1 or if nums[i]>nums.size() i++
but again what if 0 or a negative number is present in an array there are no negative locations right?
So if nums[i] =i+1 or if nums[i]>nums.size() or if nums[i]<=0 just ignore that element and proceed.
*/
After taking care of all these caviats we can finally try to simply traverse the array and if nums[i]!=i+1 i+1 would be our answer.

    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while(i<nums.size())
        {
            if(i+1==nums[i]||nums[i]<=0||nums[i]>nums.size())i++;
            else if(nums[i]!=nums[nums[i]-1])swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        i=0;
        while(i<nums.size()&&nums[i]==i+1)i++;
        return i+1;
    }