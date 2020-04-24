/*
The inital intuition that comes to you might be 2 pointers but that method wont work here.
This is because they are asking nuber of times.
This would beam our onloy option would be a hash table.
Store precmputed values in a hash table and use them later on.
So how do we use a hash table here?
We are going to use prefix sum algorithm with a bit of manipulation.
we are going to compute sum and if an sum-k if present in the hash table then the sub array with 
sum k is present.
Let me demonstate:
[1,2,3,5,6,-3]   k = 3
first my have a map mapping 0 to 1 to catch the 1st occurence of the subarray of sum k.
sum            map
0              0 -> 1
1              1 -> 1
3              3 -> 2  as(3-3 = 0 is present in the map)     count=1
6              6 -> 3  as(6-3 = 3 is present in the map)     count=2   
11             11 -> 1
17             17 -> 1
14             14 -> 1 as(14-3=11 is present in the map)     count=3

thus the count is 3.
*/

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map{{0,1}};
        int sum=0,count=0;
        for(int x:nums)
        {
            sum+=x;
            count+=map[sum-k];
            map[sum]++;
        }
        return count;
    }

