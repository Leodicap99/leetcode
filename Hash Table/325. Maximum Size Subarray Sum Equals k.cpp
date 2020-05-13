/*
The solution this given here is by using a map.
Keep summing up the integers present in the array if sum-k exists check if i-maps[(sum-k)] beats ur answer till then where map[sum] stores the index
of the array

There can be a case where the sum will be equal to k so we can check if (i+1) beats ans or not.

[1, -1, 5, -2, 3] k=3;
 ^
 |
 i 

sum=1
sum!=k
1-3=-2 doesnt exist in the map 
ans=0
map[1]=0<---map[sum]=i 

[1, -1, 5, -2, 3] 
     ^
     |
     i

sum=0
sum!=k 
0-3=-3 doesnt exist in the map 
ans=0
map[0]=1

[1, -1, 5, -2, 3] 
        ^
        |
        i

sum=5
sum!=k 
5-3=2 doesnt exist in the map 
ans=0
map[5]=2

[1, -1, 5, -2, 3] 
            ^
            |
            i

sum=3
sum==k so ans=4(ans=i+1) 
//skip doesnt exist in the map 
ans=4
map[3]=3

[1, -1, 5, -2, 3] 
               ^
               |
               i

sum=6
sum!=k 
6-3 doesnt exist in the map 
ans=4
map[6]=4

Thus the answer is 4
*/
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int ans=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k)ans=i+1;
            else if(map.count(sum-k))
            {
                ans=max(ans,i-map[sum-k]);
            }
            if(!map.count(sum))
            map[sum]=i;
        }
        return ans;
    }
