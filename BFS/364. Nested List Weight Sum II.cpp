/*
The solution discussed here will be BFS.
We first push the vector<NestedInteger> into the queue.
We keep a currsum which calculates the current sum for each level and pushed into the another queue of int.

Now while calculatint the answer we add the product of the front of the queue and the q size.

*/
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<vector<NestedInteger>> q;
        queue<int> q_final;
        q.push(nestedList);
        while(!q.empty())
        {
            int n=q.size();
            int currsum=0;
            for(int i=0;i<n;i++)
            {
                vector<NestedInteger> p=q.front();
                q.pop();
                for(NestedInteger ni:p)
                {
                    if(ni.isInteger())
                        currsum+=ni.getInteger();
                    else
                        q.push(ni.getList());
                }
            }
            q_final.push(currsum);
        }
        int ans=0;
        while(!q_final.empty())
        {
            ans+=q_final.front()*q_final.size();
            q_final.pop();
        }
        return ans;
    }