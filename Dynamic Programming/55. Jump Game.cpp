/*
This is can be solved in many ways. The approach i will be taking is greedy. Reason being i can bring down the time complexity
to o(n).
Approach:

nums =     2  3  1  1  4
indices--> 0  1  2  3  4

I ll keep picking the best solution i have at my current position.(definition of greedy). 

let me have a variable lets say jump that records my greedy chice i have taken.
At  index 0 my greedy choice would be to obviously take the current element
jump=nums[i]+i=2+0 = 2
Now i move on to the index and pick the better one among the 2.
Since jump = nums[i]+i = 4>2 i will greedily pick this element.
Now i have i go to the next index = 2
jump = nums[i]+i = 3<jump so i dont do anything

Remember: At each index i check if jump<i if so return false

I keep moving on and since my jump never exceeds i the final answer is true.
Lets test this logic on a test case which return false:

nums =   1 1 0 0 3
indices->0 1 2 3 4

here jump will take value 1+0 =1 initially.
Then it takes 1+1=2 .
At index 2 it sticks with the original value of jump.
Finally when it reaches index 3 the jump value<i thus returning false.
*/
    bool canJump(vector<int>& nums) {
        int jump=0;
        for(int i=0;i<nums.size();i++)
        {
            if(jump<i)return false;
            jump=max(jump,nums[i]+i);
        }
        return true;
    }
