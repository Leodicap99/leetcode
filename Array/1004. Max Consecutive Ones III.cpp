/*
The question is rephrased as find the longest subarray with k zeroes.

We approach this problem in this way we use 2 pointers to solve this question.
We keep incrementing a variable lets say z until it reaches k
Then we keep incrementing the next pointer till z=k and we simultaneously cache the maximum.


*/

    int longestOnes(vector<int>& A, int k) {
        int l=0,r=0,z=0,ans=0;
        while(r<A.size())
        {
            if(A[r]==0)z++;
            while(z>k)
            {
                if(A[l++]==0)z--;
            }
            ans=max(r-l+1,ans);
            r++;
        }
        return ans;
    }