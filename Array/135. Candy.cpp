class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> t(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                t[i]=t[i-1]+1;                
        }
        for(int i=n-1;i>0;i--)
        {
            if(ratings[i-1]>ratings[i])
                t[i-1]=max(t[i-1],t[i]+1);
        }
        int ans=0;
        for(int i=0;i<n;i++)ans+=t[i];
        return ans;
    }
};
