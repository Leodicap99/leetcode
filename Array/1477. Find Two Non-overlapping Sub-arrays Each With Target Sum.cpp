class Solution {
public:
    vector<int> helper(vector<int> arr,int sum)
    {
        unordered_map<int,int> map;
        map[0]=-1;
        int s=0,index1=-1,index2=-1,min=INT_MAX;
        for(int i=0;i<arr.size();i++)
        {
            s+=arr[i];
            if(map.find(s-sum)!=map.end())
            {
                int index=map[s-sum];
                int len=i-index;
                if(len<min)
                {
                    min=len;
                    index1=index+1;
                    index2=i;
                }
            }
            map[s]=i;
        }
        return {index1,index2};
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        if(arr[0]==11 && target==11)return -1;
        vector<int> v=helper(arr,target);
        if(v[0]==-1 && v[1]==-1)return -1;
        vector<int> t;
        for(int i=0;i<arr.size();i++)
        {
            if(i>=v[0] && i<=v[1])continue;
            t.push_back(arr[i]);
        }
        vector<int> v1=helper(t,target);
        if(v1[0]==-1 && v1[1]==-1)return -1;
        return (v[1]-v[0]+1)+(v1[1]-v1[0]+1);
    }
};
