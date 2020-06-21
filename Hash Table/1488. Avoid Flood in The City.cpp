class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int> map;
        set<int> s;
        vector<int> ans;
        for(int i=0;i<rains.size();i++)
        {
            if(rains[i]==0)
            {
                s.insert(i);
                ans.push_back(1);
            }
            else
            {
                int lakes=rains[i];
                if(map.count(lakes))
                {
                    auto it=s.lower_bound(map[lakes]);
                    if(it==s.end())return {};
                    int dryday=*it;
                    ans[dryday]=lakes;
                    s.erase(dryday);
                }
                map[lakes]=i;   
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
