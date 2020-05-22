class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string s;
        unordered_set<string> set;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                s+=to_string(board[i][j]);
            } 
        }
        set.insert(s);
        vector<vector<int>> dir={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        queue<string> q;
        q.push(s);
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string t=q.front();
                q.pop();
                if(t==target)return ans;
                int z=(int)t.find("0");
                for(auto &x:dir[z])
                {
                    string temp=t;
                    swap(temp[x],temp[z]);
                    if(set.count(temp)==0)
                    {
                        q.push(temp);
                        set.insert(temp);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
