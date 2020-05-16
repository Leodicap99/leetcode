   
/*
Unioin find approach:-Time Complexity:-O(nlogn)
*/
     int find(int x,vector<int> &parent)
    {
        return parent[x]==x?x:find(parent[x],parent);
    }
    int earliestAcq(vector<vector<int>>& logs, int N) {
        sort(logs.begin(),logs.end());
        vector<int> groups(N);
        for(int i=0;i<N;i++)groups[i]=i;
        vector<int> rank(N,0);
        int count=0,ans=INT_MIN;
        for(auto &x:logs)
        {
            int group1=find(x[1],groups);
            int group2=find(x[2],groups);
            if(group1!=group2)
            {
                N--;
                if(N==1)return x[0];
                groups[group1]=group2;
            }
        }
        return -1;
    }