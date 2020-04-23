/*
To tackle this problem we will be using mergesort algorithm.
we are gonna keep inserting the smallest element in an auxialliary array say ans
until one of the array is empty.After u reach the end of any one  array just copy
the rest of the other array into ans.
let me demonstrate
lets take these two arrays as an example:
nums1 = [1, 2]
nums2 = [3, 4]
let our auxialliary array be ans.
ans=[]
now lets pick the smallest element in both th arra.
NOTE:Since both the arrays are sorted we try to excercise this power
in getting this answer.
lets have 2 pointers each pointing to the smallest element in both the arrays which
is 0 sice the arrays are sorted
 i
 |
 v
[1,2]
[3,4]
 ^
 |
 j
 since nums1[i]<nums2[j] we copy the element into ans ans move i to the next element.
 ans=[1]
   i
   |
   v
[1,2]
[3,4]
 ^
 |
 j 
 again check for the smaller element.Since nums1[i]<nums2[j] we do the same procedure as before.
 ans[1,2]
     i
     |
     v
[1,2]
[3,4]
 ^
 |
 j 
 Now since we finished traversing one of the elements we just copy the remainingg elements into ans.
 let me demonstrate
     i
     |
     v
[1,2]
[3,4]
 ^
 |
 j 
 ans[1,2,3]
     i
     |
     v
[1,2]
[3,4]
   ^
   |
   j
 ans=[1,2,3,4]
     i
     |
     v
[1,2]
[3,4]
     ^
     |
     j 
 thus we have finished filling the auxialliary array.
 Now to find the median follow the steps
 Step1:check if the size of the array is even or odd. 
 Step2:If even:
       [1,2,3,4]
          ^ ^
          | |
         (2+3)/2<--------median
 Step3:If Odd:
     [1,2,3]
        ^
        |
        2<----------median
 */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int i=0,j=0,k=0,m=nums1.size(),n=nums2.size();  
     int ans[m+n];
     while(i<m||j<n)
     {
     	if(i<m&&j<n)
     	{
     		if(nums1[i]<nums2[j])
     			ans[k++]=nums1[i++];
     		else
     			ans[k++]=nums2[j++];
     	}
     	else if(i<m)
     		ans[k++]=nums1[i++];
     	else
     		ans[k++]=nums2[j++];
     } 
     double res;
     if((m+n)%2==0)
     res=(double)(ans[(m+n)/2]+ans[(m+n)/2-1])/2.0;//<-------typecasting to double
     else
     	res=(double)ans[(m+n)/2];
     return res;
    }