/*
We will be using minheap as it is more space optimized.
The idea is to store the top k frequent words in a minheap that means the most frequent word will be at the end of the minheap(leaf of the tree).
we have to build a heap such a way that it stores the frequency of the string as well as the string itself.
*/
    struct comp
    {
        bool operator()(const pair<int,string> &a,const pair<int,string> &b)
        {
            if(a.first!=b.first)
                return a.first>b.first;
            else
                return a.second<b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        priority_queue<pair<int,string>,vector<pair<int,string>>, comp> pq;
        vector<string> ans(k);
        for(string &w:words)
            map[w]++;
        for(auto it=map.begin();it!=map.end();it++)
        {
            if(pq.size()<k)
            pq.push({it->second,it->first});
            else
            {
                if(pq.top().first<it->second||(pq.top().first==it->second && pq.top().second>it->first))
                {
                    pq.pop();
                    pq.push({it->second,it->first});
                }
            }
        }
        while(!pq.empty())
        {
            ans[--k]=pq.top().second;
            pq.pop();
        }
        return ans;
    }