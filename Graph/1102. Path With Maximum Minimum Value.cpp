/*
Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).
*/

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        priority_queue<tuple<int,int,int>> pq;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        pq.push({A[0][0],0,0});
        int n=A.size(),m=A[0].size(),ans=A[0][0];
        int a;
        A[0][0]=-1;
        while(!pq.empty())
        {
            auto [a ,i, j]=pq.top();
            pq.pop();
            ans=min(ans,a);
            if(i==n-1 && j==m-1)break;
            for(auto &b:dir)
            {
                int x=b[0]+i;
                int y=j+b[1];
                if(x<0||x>=n||y<0||y>=m||A[x][y]==-1)continue;
                pq.push({A[x][y],x,y});
                A[x][y]=-1;
            }
        }
        return ans;
    }
};
