/*
We will have to store the elements in a multiset and check if the last element and first element difference is greater than limit.
We will be having two pointers let i & j be the pointers.
We keep incrementing i until the first element and the last element of the multiset is greater than limit.
If so we find the element nums[i] and erase it fromt our multiset and increment i.
We simutaneously cache in the maximum
nums = [8,2,4,7], limit = 4
        ^
        |
        i,j

multiset m = [8]
check if (*m.rbegin()-m.begin()>limit)
            |
            last element(NOTE:m.end() is not the last element it is the terminating character).
8-8<=4 so we continue whilst storing the maximum = 1

[8,2,4,7]
 ^ ^
 | |
 i j
m=[8,2]

if (*m.rbegin()-m.begin()>limit) condition:true
	so we search for nums[i] and delete.
m=[2]


[8,2,4,7]
   ^ ^
   | |
   i j
m[2,4]
if (*m.rbegin()-m.begin()>limit) condition:false
maximum=2

[8,2,4,7]
   ^   ^
   |   |
   i   j
m=[2,4,7]
if (*m.rbegin()-m.begin()>limit) condition:true
so we search for nums[i] and delete.
m=[2,4,7]

[8,2,4,7]
     ^   ^
     |   |
     i   j
as j has terminated our answer will become 2
*/
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int j=0,ans=1;
        for(int i=0;i<nums.size();i++)
        {
            m.insert(nums[i]);
            while(!m.empty() && *m.rbegin()-*m.begin()>limit)
                m.erase(m.find(nums[j++]));
            ans=max(ans,i-j+1);
        }
        return ans;
    }