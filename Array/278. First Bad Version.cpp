/*
Just do a binary search fromt 1 to n
*/
    int firstBadVersion(int n) {
        int l=1,r=n,ans;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(isBadVersion(m))
            {
                ans=m;
                r=m-1;
            }
            else 
                l=m+1;
        }
        return ans;
    }