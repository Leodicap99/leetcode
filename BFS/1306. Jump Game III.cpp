/*
The way to solve this question is using BFS/DFS.
Here i ahve given a BFS solution.
I ll first push the starting position into the queue and start exploring is neighbors.
I will maintain a boolean array to make sure i dont get caught into a loop
Let me explain how a loop can occur:-
[3,0,2,1,2]
start=2

i can move either left or right.
Let me for example take this route

2->3->1->2
This will go indefinitely.

Let me explain the algorithm with the same example
 0 1 2 3 4  <---indices
[3,0,2,1,2]
start=2

q=[2](Remember that the start position they give is the index)
we pop 2 out and store it into i.
We mark 2 as visited
check if if(i+arr[i]>=n)false or if(i-arr[i]<0)false

Thus we push i+arr[i] and i-arr[i] into the queue.
q=[0,4]
Pop 0 out
check if if(i+arr[i]>=n)false or if(i-arr[i]<0)true
So we push only i+arr[i] into the arry.

q=[4,3]
Pop 4 out
check if if(i+arr[i]>=n)true or if(i-arr[i]<0)false
So we push only i-arr[i] into the arry.

q=[3,3]
Note that 3 was already we visited so we popped out

q[3]
Again it gets popped out.

As 0 was never encountered in our traversal we return false.
*/
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        q.push(start);
        vector<bool> visited(n,false);
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            if(arr[i]==0)return true;
            if(!visited[i]){
            visited[i]=true;
            if(i+arr[i]<n)q.push(i+arr[i]);
            if(i-arr[i]>=0)q.push(i-arr[i]);
            }
        }
        return false;
    }

