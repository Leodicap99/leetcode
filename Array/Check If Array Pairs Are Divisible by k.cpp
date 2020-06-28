/*
https://leetcode.com/contest/weekly-contest-195/problems/check-if-array-pairs-are-divisible-by-k/
*/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> a(k);
        for(int num:arr)
        {
            a[(num%k+k)%k]++;
        }
        for(int i=1;i<k;i++)
        {
            if(a[i]!=a[k-i])return false;
        }
        return a[0]%2==0;
    }
};
