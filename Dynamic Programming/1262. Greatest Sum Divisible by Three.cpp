/*
This is a really tricky problem.
One thing u have to note is that when i divide any number by 3 my maximum number would be 2.
One way to solve this method is to ste the maximum sum with remainders 0,1,2
[3,6,5,1,8]        [0,0,0] <----auxiliary array storing the maimum sum int the remainders position
 ^
 |
 i
sum = 3            [3,0,0] <---3%3=0


[3,6,5,1,8]        [9,0,0] <----9%3=0
   ^
   |
   i
sum = 3+6 = 9

[3,6,5,1,8]        [9,0,14] <----14%3=2
   ^
   |
   i
sum = 9+5=14

[3,6,5,1,8]        [15,0,14] <----15%3=0
   ^
   |
   i
sum = 14+1=15

[3,6,5,1,8]        [15,0,23] <----23%3=2
   ^
   |
   i
sum = 15+8=23

This approach gives me a max sum of remainder 0 as 15 but that isnt an answer
Our approach here finds the maximum sum of a subarray that is divisible by 3
But we need to find a subsequence(not necesaaruly have to by contiguos elements).

Just look at our auxiliary array carefully.

[3,0,0]             [3,] 
[9,0,0]             [3,6,]
[9,0,14]            [3,6,5,]
[15,0,14]           [3,6,5,1,]
[15,0,23]           [3,6,5,1,8]

If i were to add every new number to the sums present in the auxiliary array and mod it and check if it beats any of the sum would that work?

[3,0,0]             [3,] 
[9,0,0]             [3,6,]
[9,0,14]            [3,6,5,]
[15,10,14]           [3,6,5,1,] 1 is added to 9 0 and 14 = 10, 1 and 15
[18,22,23]           [3,6,5,1,8]  8 is added to 15,10 and 14 which gives 23,18,22 where 18 beats 15 

*/
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp={0,0,0};
        for(int x:nums)
        {
            vector<int> dp1=dp;
            for(int a:dp1)
            {
                dp[(x+a)%3]=max(dp[(x+a)%3],x+a);
            }
        }
        return dp[0];
    }