class Solution {
public:
    int minDays(int n) {
        if(n<3)return n;
        unordered_set<int> s;
        queue<int> q;
        q.push(n);
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x=q.front();
                q.pop();
                if(s.find(x)!=s.end())continue;
                s.insert(x);
                if(x<=0)return ans;
                if(x%3==0)q.push(x/3);
                if(x%2==0)q.push(x/2);
                q.push(x-1);
            }
            ans++;
        }
        return ans;
    }
};
