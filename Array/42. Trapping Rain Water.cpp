/*
Algorithm to solve this question:

1. Keep two poiners one to the 0(l) and the other to height.size()-1 (r).
2. Initialize a maxleft and maxright to 0.
3. Start a loop and check if height[left]<=height[right] If yes Then this will contribute to ur answer as anything above this causes overflow.
4. If the height is greter than maxleft  update maxleft and increment maxleft.
5. If its lesser than max left that mean this and maxleft can hold water -> ans=maxleft-left[i] and increment left pointer.
6. if 3. fails that means there is a potential of storing water in the right side.
7.If the height[right] is greater than maxright update maxright and move the pointer backward.
8. If its lesser ans=maxright-height[i].
*/
    int trap(vector<int>& height) {
        int ans=0,left=0,right=height.size()-1;
        int maxleft=0,maxright=0;
        while(left<right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>maxleft)maxleft=height[left];
                else ans+=maxleft-height[left];
                left++;
            }
            else
            {
                if(height[right]>maxright)maxright=height[right];
                else
                    ans+=maxright-height[right];
                right--;
            }
        }
        return ans;
    } 