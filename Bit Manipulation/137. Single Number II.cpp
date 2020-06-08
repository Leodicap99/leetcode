class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenonce=0,seentwice=0;
        for(int &x:nums)
        {
            seenonce=~(seentwice)&(seenonce^x);
            seentwice=~(seenonce)&(seentwice^x);
        }
        return seenonce;
    }
};
