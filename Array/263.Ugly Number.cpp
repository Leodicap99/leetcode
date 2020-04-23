/*The intuition that first comes to our minds is that if(num%2==0||num%3==0||num%5==0)return true
Well this might pass some test cases but it is absolutely wrong.
let me demonstrate:
Let num=14;
its prime factors are:1,2,7,14
but the questions says apart from 1 and the number itself only 2,3,5 are allowed
So how do we tackle this problem?
We try to keep dividing the by 2 as long as the number is divisble by 2
Then with the current number we keep dividing by 3 as long as its divisble by 3
similarly for 5.
If the final number that we get is 1 then we have got the result.
Let me demonstrate:
Let us take the same number
num=14<-----divisible by 2 so keep dividing
14/2=7<-----not divisible by 2 so stop
7<----------not divisble by 3 so stop
7<----------not divisble by 5 so stop
the final answer we got is 7 which is not equal to 1 so return false.
Lets take another example
num=30<-----divisble by 2 so keep dividing by 2
num=15<-----not divisible by 2 so stop
num=15<-----divisble by 3 so keep dividing by 3
num=5<------not divisible by 3 so stop
num=5<------divisble by 5 so keep dividing by 5
num=1<------not divisible by 5 so stop
as 1==1 return true
*/
bool isUgly(int num) {
        if(num==0)return false;//<-----0 is neither divisble by 2,3 nor 5
        while(num%2==0)num/=2;
        while(num%3==0)num/=3;
        while(num%5==0)num/=5;
        return num==1;
    }