/*
We will be first using our traitional dp matrix solution first and then try optimizing it.
We try to create a dp matrix wih coins as rows and amount as columns.

Let amount = 5, coins = [ 2, 5]

         1  2  3  4  5     
     2                         <------DP MATRIX

     5

The proble with this structure of matrix is isthat suppose i am trying to find how many ways to get 1 from coin2
Ofcourse we know its impossible but how do u prove it using this matrix.
Generally we are going to structure our d matrix in such a way that the (i,j)th cell will tell us for j amount how many ways can i 
produce it using i,i-1,i-2..... coins(0/1 knapsack).
So for every cell we have 2 options either use the coin or we choose to  drop it because the amount is too small for us to pay even
with our smallest coin.
So in the above matrix the fault arises when i wanna pay amount 1 using coin 2,this is a case when we drop the coin so we will need
another row that say coin 0.

       0  1  2  3  4  5     

     2                         <------DP MATRIX

     5
Okay so now we have solved the above problem by using a coin which holds 0 value.But the matrix is still faulty->why?
Because example to pay 4 amount how many 2 coins are need -> i can either choose to drop or pay it using my coin 2
Here i choose to pay it so once paid i must subtract the amount by the coin i used and add check for amount 2 how many waysdid
I use to pay using coin 2.LET ME DEMONSTARTE:
4 using only coin 2 is formed by 2+2
that means if i remove 2 from 4 how many ways did i use to pay 2 will the sm=ame number of ways i use to pay 4 because i have infinite
number of coins.
So the matrix is faulty because when i pay amount 2 with coin 2 i must subtract 2 from 2 .

        0  1  2  3  4  5     
     0

     2                         <------DP MATRIX

     5
  This will be our dimensionally correct dp matrix.

  Now for amount 0 how many ways can i pay using coin0 ->1
  for amount 1 how many ways can i pay using coin 0 ->0 because how many ever coin 0s i use it will never amount to 1.
  Same goes for amount 2,3,4,5 using coin0 will be 0.
  Now for filling our coumn 1:
  for amount 0 how many ways can i pay using 2 -> 1 i can just pay coin 0.   
  same thin goes for coinf 5 

          0  1  2  3  4  5     
     0    1  0  0  0  0  0

     2    1                     <------DP MATRIX

     5    1

     Now how can i pay amount 1 using 2->0 cuz i can not pay using 2.
     how many ways can i pay 2 using coin2->1 way cuz i can just use a coin 2.
     how many ways can i pay 3 using coin2->0 way cuz i can not just using a coin 2.
     how many ways can i pay 4 using coin2->1 way cuz i can just use a coin 2. 4=2+2
     how many ways can i pay 5 using coin2->0 way cuz i can not just using a coin 2. 

          0  1  2  3  4  5     
     0    1  0  0  0  0  0

     2    1  0  1  0  1  0           <------DP MATRIX

     5    1     

     coin 5 cannot be used until the amount is 5 however we have coin 2 which can pay 2 and 4 so 1 and 3 still remain 0

             0  1  2  3  4  5     
     0       1  0  0  0  0  0

     2       1  0  1  0  1  0           <------DP MATRIX

     5       1  0  1  0  1  1

     thus 5 can got only using a 5 coin.

     seeing the above pattern we can deduce the formula

     dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]] i,j>0 and only if j>=coin[i-1];
     else 
     	dp[i][j] = dp[i-1][j] we just drop the coin.
*/

      int change(int amount, vector<int>& coins) {
        if(coins.size()==0&&amount==0)return 1;
        if(coins.size()==0)return 0;
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1));
        for(int i=0;i<=coins.size();i++)
            dp[i][0]=1;
        for(int j=1;j<=amount;j++)
            dp[0][j]=0;
        for(int i=1;i<=coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[coins.size()][amount];
    }


The optimized version just uses the above strategy :


    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;
        sort(coins.begin(),coins.end());
        for(int i=0;i<coins.size();i++)
        {
            for(int j=coins[i];j<=amount;j++) //<-----here we dont even look at amounts lesser than the coin we take
                dp[j]+=dp[j-coins[i]];
        }
        return dp[amount];
    }