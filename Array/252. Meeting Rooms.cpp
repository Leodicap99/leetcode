/*
Analogy:
We can attend all the meeting if it occurs at different timings more importantly where one meeting shouldnt clash with another.

We sort the array according to the first elements in the matrix.
If i ever encounter a clash i will return false else i break from the loop and return true.

How to check for clash?
A clash occurs when two meeting occur at the same time i.e if the start timing of a later meeting is lesser than the end timing of
earlier meeting a clash occurs.

So the algorithm is simple
1. We first sort the matrix acc to the first elements in the matrix.
2. We start from the second  meeting and check if the start time is lesser than the end time isf so return false there itself.
3. break from the loop and return true.
*/
    struct comp
    {
        bool operator()(const vector<int> &a,const vector<int>&b)      //<-----This is how we sort 2d matrices.
        {
            return a[0]<b[0];
        }
    }compare;
    bool canAttendMeetings(vector<vector<int>>& interval) {
        if(interval.size()<=1)return true;
        sort(interval.begin(),interval.end(),compare);
        for(int i=1;i<interval.size();i++)
        {
            if(interval[i][0]<interval[i-1][1])return false;
        }
        return true;
    }
