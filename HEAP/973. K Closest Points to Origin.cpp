/*
The give away to a heap question is whenever a question asks for k closest or k smallest or k largest.
Though these questions might me implemented using other algorithms heap will allow to simply the problem as well as code.
Your code will look compact and u can rectify ur mistakes quickly.
This can be solved using miheap or maxheap.
The only probem with min heap is space.It will store all the array elements and this can be costly of large elemented arrays.
However using a maxheap we just need to be storing k elements.
That is all the difference between them.

Let points = [[1,3],[-2,2]], K = 1
The way to judge whether a point is clore or not is to find the euclidean distance.
Note:u dont have to perform square root and make the code look complex moreover it s more prone to errors.

dist = x*x+y*y
We have the choose the k smallest distance values.

Lets see the above question:

dist = 1*1 + 3*3 = 10
dist = -2*-2 + 2*2 = 8

We can see that dist of the 2nd element is smaller and question asks for only 1 so we pushback that element into our ans array.
*/    

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        if(points.size()==0)return ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++)
        {
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(pq.size()<k)
            pq.push({dist,{points[i][0],points[i][1]}});
            else
            {
                if(dist<pq.top().first)
                {
                    pq.pop();
                    pq.push({dist,{points[i][0],points[i][1]}});
                }
            }
        }
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }

