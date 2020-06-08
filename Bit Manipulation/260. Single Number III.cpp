class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int b=0;
        for(int i:nums)b^=i;
        int diff=b&(-b);
        int x=0;
        for(int i:nums)if((i&diff)!=0)x^=i;
        return {x,b^x};
    }
};
