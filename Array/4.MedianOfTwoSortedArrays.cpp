class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x=nums1.size(),y=nums2.size();
        if(x>y)return findMedianSortedArrays(nums2,nums1);
        int l=0,r=x;
        while(l<=r)
        {
            int partitionx=(l+r)/2;
            int partitiony=(x+y+1)/2-partitionx;
            int maxleftx=(partitionx==0)?INT_MIN:nums1[partitionx-1];
            int minrightx=(partitionx==x)?INT_MAX:nums1[partitionx];
            int maxlefty=(partitiony==0)?INT_MIN:nums2[partitiony-1];
            int minrighty=(partitiony==y)?INT_MAX:nums2[partitiony];
            if(maxleftx<=minrighty && maxlefty<=minrightx)
            {
                if((x+y)%2==0)
                    return ((double)max(maxleftx,maxlefty)+min(minrightx,minrighty))/2.0;
                else
                    return (double)max(maxleftx,maxlefty);
            }
            else if(maxleftx>minrighty)
                r=partitionx-1;
            else l=partitionx+1;
        }
        return -1;
    }
};
