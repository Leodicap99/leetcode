/*
If you keep trying to sum the square of the digits you will reach either of the two states at some point of time
1. You reach 1
2. You reach a sum which you have already reached before.

Let n=19 (Example of case 1)
sum = 1^2 + 9^2 = 82
sum = 8^2 + 2^2 = 68
sum = 6^2 + 8^2 = 100
sum = 1^0 + 0^2 + 0^2 = 1

Let n=17
sum = 1^2 + 7^2 = 50
sum = 5^2 + 0^2 = 25
sum = 2^2 + 5^2 = 29 <---
sum = 2^2 + 9^2 = 85
sum = 8^2 + 5^2 = 89
sum = 8^2 + 9^2 = 145
sum = 1^2 + 4^2 + 5^2 =52
sum = 5^2 + 2^2 = 29  (which is already present)
*/
    bool isHappy(int n) {
       int ans=0;
        unordered_set<int> s;
        while(1)
        {
            int sum=0;
            while(n)
            {
                sum+=pow(n%10,2);
                n/=10;
            }
            if(s.find(sum)!=s.end())break;
            s.insert(sum);
            if(sum==1)return true;
            n=sum;
        }
        return false;
    }