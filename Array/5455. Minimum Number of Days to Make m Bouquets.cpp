class Solution {
public:
    bool check(vector<int>& v, int m, int k,int mid)
    {
        int c=0,tot=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<=mid)
            {
                c++;
                if(c==k)
                {
                    tot++;
                    c=0;
                }
            }
            else c=0;
        }
        if(tot>=m)return true;
        return false;
    }
    int minDays(vector<int>& v, int m, int k) {
        int l=0,r=*max_element(v.begin(),v.end()),ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(v,m,k,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
