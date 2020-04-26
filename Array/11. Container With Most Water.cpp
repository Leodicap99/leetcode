/*
The approach to this solution that iw ill be taking is two pointer and a bit of common sense.
I will place my left pointer (l) at 0 and right pointer (r) at height.size()-1.
I will assign breadth eaqual to the size of the array - 1 (Because on account of the distance from the first index u take till the last).
Now i will check the smaller height of the two and set that as the current height. Why> Because the smaller rod only will acount for
the height because anything above that will  cause an overflow at the smaller side.

How do we move the pointers?
We move the pointers based on which index as the bigger height. Why? -> Cuz The bigger height has the potential of yielding me 
a bigger area because irrespective of what height I will be taking breadth wiill decrease by 1.

Input: [1,8,6,8,3,7]
        ^         ^
        |         | 
        l         r
area = 0
breadth = 5
l=0                  ----->    height[l]<height[r] we move left pointer forward and area = max(area,height[l]*breadth)
r=5                            Similarly use this logic if height[l]>height[r]

decrement breadth

Continue this until l==r.
*/

    int maxArea(vector<int>& height) {
        int breadth=height.size()-1,l=0,r=height.size()-1;
        int ans=0;
        while(l<r)
        {
            bool flag=0;
            int length;
            if(height[l]<=height[r])
            {
                flag=1;
                length=height[l];
            }
            else
                length=height[r];
            ans=max(ans,length*breadth);
            if(flag)l++;
            else r--;
            breadth--;
        }
        return ans;
    }
