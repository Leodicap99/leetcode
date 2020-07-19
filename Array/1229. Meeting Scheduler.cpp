/*
1229. Meeting Scheduler
Medium

Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.  

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.
*/


class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        vector<int> ans;
        int i=0,j=0;
        while(i<slots1.size() && j<slots2.size())
        {
            int low=max(slots1[i][0],slots2[j][0]),high=min(slots1[i][1],slots2[j][1]);
            if(high-low>=duration)return {low,low+duration};
            if(high==slots1[i][1])i++;
            else j++;
        }
        return {};
    }
};
