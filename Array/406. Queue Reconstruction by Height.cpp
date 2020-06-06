    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](vector<int> &a,vector<int> &b)
             {
                return (a[0]>b[0])||(a[0]==b[0] && a[1]<b[1]); 
             });
        vector<vector<int>> ans;
        for(auto &x:p)
            ans.insert(ans.begin()+x[1],x);
        return ans;
    }
