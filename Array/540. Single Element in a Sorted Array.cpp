/*
We use binary search to solve this.

The problem of using binary search is how to determine the conditions inside the while loop?

Well this logic maynot come that intuitively but if u observe a few examples u will quickly get the idea.

Let num=[1,1,2,3,3,4,4,8,8]
         0,1,2,3,4,5,6,7,8 <----indices

Let us do our traditional binary search start and see what happens:-
l=0,r=nums.size()-1=8
m=4

[1,1,2,3,3,4,4,8,8]
         ^
         |
         mid
Notice that once we hit the mid and remove its duplicate(if it doesnt have any that would be the answer)-> the answer will lie in the subarray 
constaining odd length (cuz everything will be paired up except for 1 thus odd length)

[1,1,2, ,4,4,8,8]
\_____/  \______/
   |         |
 odd        even 
 length     length

 Thus our answer is present in the odd length of the array.

 But one problem here  is how to find after the split whether its odd and even by making sure we stick to the complexity of o(logn).

 U initialize a bool variable and check if the r-mid is even or not.
[1,1,2,3,3,4,4,8,8]
For this example 8-4=4 is even that mean ur answer cant lie in the right side of the array.
So we can test our solution like this

bool even_length=(r-m)%2==0
if(nums[m]==nums[m-1])
{
	if(even_length)
		r=m-2;
	else 
		l=m+1;
}

did u understand? ->I am writing the code to suit for the above example 

Now what if nums[m]==nums[m+1]
nums=[1,1,4,4,5,5,6,7,7]
              ^
              |
              mid 
Here r-m=even but wait...
m+1 has to be removed too 
thus eventhough the right side show even due to the above property it has to odd cuz we subtract 1 element
Then just follow the same procedure

if(nums[m]==nums[m+1])
{
	if(even_length)
		l=m+2;
	else
		r=m-1;
}
*/

Code:-

    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            bool even_length=(r-m)%2==0;
            if(nums[m]==nums[m+1])
            {
                if(even_length)
                    l=m+2;
                else
                r=m-1;
            }
            else if(nums[m]==nums[m-1])
            {
                if(even_length)
                    r=m-2;
                else
                    l=m+1;
            }
            else
                return nums[m];
        }
        return nums[l];
    }


