We have to use bit mani pulation for this as it is way faster than the brute force method
It is as simple as these steps 
1. Check if the number is even or odd.
2. If the number is even right shift and increment the answer.
3 If the number is odd DONOT subtract it, as right shif will get back to half the value
All u have to do is increment the answer by 2.
Let 
num = 9 <--- as the number is odd we increment answer twice.          count=1
9/2 = 4 <--- as the number is even we increment the answer by 1       count=2
4/2 = 2 <--- as the number is even we increment the answer by 1       count=3
2/2 = 1 <--- as the number is even we increment the answer by 1       count=4
1/2 = 0 <--- as the number is even we increment the answer by 1       count=5
Thus the answer is 5.


    int numberOfSteps (int num) {
        int ans=0;
        while(num>0)
        {
            if(num%2==1)ans++;
            num>>=1;
            ans++;   <----as 1 is odd it will count twice which we dont want.
        }
        return ans-1;
    }