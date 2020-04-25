We will be solving this question using heaps.
The main idea will be to use a max heap to store k smallest elements.
We can solve this using a min heap also but using a max heap saves memory as in stores only k elements.

Let nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 we are going to create a heap containing pair(sum,pair(nums1[i],nums2[j])).
 Thus the heap will heapify itself making the largest sum come on top.

              maxheap

           |                |
           |                |    <-------nums1[0] &&  nums2[0]
           |                |
           |   {3,{1,2}}    |
           |________________|   

           We will keep proceeding until we hit the size k.

             maxheap

           |                |
           |                |    <-------nums1[0] &&  nums2[1]
           |   {5,{1,4}}    |
           |   {3,{1,2}}    |
           |________________| 


             maxheap

           |                |
           |   {7,{1,6}}    |    <-------nums1[0] &&  nums2[2]
           |   {5,{1,4}}    |
           |   {3,{1,2}}    |
           |________________| 


           After this we keep checking if the sum is smaller than the top of the heap if yes replace.

           However in this example this is the answer.

           Before pushing it to the array reverse it as the heap stores it in decreasing sum.

           [[1,2],[1,4],[1,6]]  this will be the final output


      vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)pq.push({sum,{nums1[i],nums2[j]}});
                else if(sum<pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }