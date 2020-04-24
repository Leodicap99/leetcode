/*
Though the question asks without recursion it is nearly impossible to find the solution to this problem.
As it is based on a congruency fromula for digit roots.
here in the recurdion we just brute force the solution to htis question.
Lets take an example
num = 38
        
        |     |
        |  38 | <------Recursion stack
        |_____|

  38 is popped out of the stack.
  3 + 8 =11 which is pushed into the stack.

        |     |
        |  11 | <------Recursion stack
        |_____|

  11 is popped ot of the stack
  1+1 =2
  as this is lesser than 10 2 is returned to the caller function.

*/
      int addDigits(int n) {
        if(n<10)return n;
        int s=0;
        while(n)
        {
            s+=n%10;
            n/=10;
        }
        return addDigits(s);
    }