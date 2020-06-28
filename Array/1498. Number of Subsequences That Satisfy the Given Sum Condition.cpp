class Solution {
public:
    int numSubseq(vector<int>& arr, int target) {
        vector<int> precomp = {0, 1};
        for (auto i = 0; i < arr.size(); ++i) {
        precomp.push_back((precomp.back() << 1) % 1000000007);
    }
        sort(arr.begin(),arr.end());
        int l=0,r=arr.size()-1;
        int ans=0;
        while(l<=r)
        {
            if(arr[l]+arr[r]>target)r--;
            else
            {
                ans = (ans + precomp[r - l + 1]) % 1000000007;
                l++;
            }
        }
        return ans;
    }
};
