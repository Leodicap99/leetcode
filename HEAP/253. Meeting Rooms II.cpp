/*
Question:
For those who dont have premium this is the question:
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:

Input: [[7,10],[2,4]]
Output: 1

Answer:
We start by sorting the matrix according to the first elements because it has to be scheduled with increasing time.
If the start time is greater than the end time of the previous meeting we dont need to allocate an extra room.
However if the start time is lesser than the end time of the previous meeting we hve to allocate a new room.
We have sorted the start time but for the end time we use a minheap.
We store the end times in the min heap because if the start time of a later meeting is greater than the smallest end time of the other we can allocate the same room for it.
time complexity---->o(nlogn)
space complexity---->o(n)
*/
   struct Compare
    {
        bool operator()(const vector<int> &one, const vector<int> &two)
        {                                                                     //<-------this is how we sort 2d matrices
            return one[0] < two[0];
        }
    }compare;
    int minMeetingRooms(vector<vector<int>>& interval) {
        if(interval.size()==0)return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(interval.begin(), interval.end(), compare);
        pq.push(interval[0][1]);
        for(int i=1;i<interval.size();i++)
        {
            if(interval[i][0]>=pq.top())pq.pop();
            pq.push(interval[i][1]);
        }
        return pq.size();
    }