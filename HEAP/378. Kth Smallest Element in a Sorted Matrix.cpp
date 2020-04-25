/*
Check out my kth laegest element in a stream it is based on the same principle.
We use a max heap to store elements which is of size k.
We store k smallest element into it with the kth smallest element on the top.
*/

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                if(pq.size()<k)pq.push(matrix[i][j]);
                else if(matrix[i][j]<pq.top())
                {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }