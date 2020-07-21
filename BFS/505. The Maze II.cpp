/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
*/

class Solution {
public:
    using piii=pair<int,pair<int,int>>;
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& d) {
        int n=maze.size(),m=maze[0].size();
        vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        priority_queue<piii,vector<piii>,greater<piii>> pq;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dist(n,vector<int>(m));
        pq.push({0,{start[0],start[1]}});
        while(!pq.empty())
        {
            piii p=pq.top();
            pq.pop();
            if(vis[p.second.first][p.second.second])continue;
            if(p.second.first==d[0] && p.second.second==d[1])return p.first;
            vis[p.second.first][p.second.second]=true;
            for(auto &dir:dirs)
            {
                int x=p.second.first;
                int y=p.second.second;
                int c=p.first;;
                while(x+dir[0] >= 0 && x+dir[0] < n && y+dir[1] >= 0 && y+dir[1] < m && maze[x+dir[0]][y+dir[1]] != 1)
                {
                    x+=dir[0];
                    y+=dir[1];
                    c++;
                }
                if(vis[x][y])continue;
                if(dist[x][y]==0||c<dist[x][y])
                {
                    dist[x][y]=c;
                    pq.push({c,{x,y}});
                }
            }
        }
        return -1;
    }
};
