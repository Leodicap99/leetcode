What u want to keep doing in this problem is recording the maximum profit and recording the minimum element at the same time.
say the array is [4,3,6,8,9].
let my smallest element be INT_MAX
so my profit will be max(profit,arr[i]-smallest)
so at the same time we will be recording the minimum 
[4,3,6,8,9]
profit  smallest
  0      INT_MAX
  0        4
  0        3
  3        3
  5        3
  6        3
  Thus 3 is the final answer.

      int maxProfit(vector<int>& prices) {
        int profit=0,smallest=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            profit=max(profit,prices[i]-smallest);
            smallest=min(smallest,prices[i]);
        }
        return profit;
    }