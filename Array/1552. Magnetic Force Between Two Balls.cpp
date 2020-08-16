class Solution {
public:
    int maxDistance(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int l=1,r=arr[n-1]-arr[0];
        int ans=0;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(check(arr,n,k,m))
            {
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
    private:
    bool check(vector<int>& arr, int n,int k,int m)
    {
        int p=arr[0];
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]-p>=m)
            {
                p=arr[i];
                count++;
            }
        }
        return count>=k;
    }
};
