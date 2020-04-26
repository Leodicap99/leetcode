We can use the bruteforce logic of extracting all the digits and reversing it as it throws an error for really 
large numbers.
How we tackle this proble is by using a mix of queue and string.
we extract evry digits from the least significant digit and simulatneously push it into our queue.
We then create a string which takes value fom the front of the queue.
Then we use the stol function to check if its greater than INT_MAX or less than INT_MIN return 0 then else return  stoi(string).
                 ^                                                                                                    ^
                 |                                                                                                    |
             string to long                                                                                       string to int             

   Let Input: 123

   we keep extracting the digits fromt the least signitficant digit and push it to our queue.

   queue :  3 2 1 
            ^
            |
           front

  we then typecast each integer from the front of the queue and add to our string .

  ans = 3 2 1

  then return stoi(ans).

  To pass all the corner test cases use stol(ans)to check if the number is greater than or less than INT_MAX and INT_MIN simulatneously.          


      int reverse(int x) {
        if(x==0)return 0;
      int sign = (x>=0)?1:-1;
        x=abs(x);
       queue<int>s;
        while(x>0)
        {
            s.push(x%10);
            x/=10;
        }
        string ans=(sign==1)?"":"-";
        while(!s.empty())
        {
            ans+=to_string(s.front());
            s.pop();
        }
        return stoll(ans)>INT_MAX||stoll(ans)<INT_MIN?0:stoi(ans);
    }