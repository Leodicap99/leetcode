/*
Here the way to tackle this problem is to visualize it.
If I were to buy the data at every small value and sell it at the immediate biggest value i can get the answer.
Let me demonstrate:
 				   7
 					\     5    6 
 					 \    /\  /\
 					  \  /  \/  4 --------->[7,1,5,3,6,4]
 					   \/	3		  
                       1
So if we were to buy at every valley and sell at evry peak we can acheive the goal given in this q.
      buy-1,3,4
      sell-5,6
      but as 4 doesnt have a pair we discard it
      profit = (sum of peaks) - (sum of valleys)
                11 - 4 = 7
*/
     int maxProfit(vector<int>& prices) {
        int ans=0,profit=0;
        int valley,peak;
        for(int i=0;i<prices.size();i++)
        {
            while(i<prices.size()-1 && prices[i]>=prices[i+1])i++;
            valley = prices[i];
            while(i<prices.size()-1 && prices[i]<=prices[i+1])i++;
            peak = prices[i];
            profit += peak-valley;
        }
        return profit;
    }
					
