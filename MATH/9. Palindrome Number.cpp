/*
You just have to keep extracting digits from the least significant bit by inserting into this intuitive mathmatical formula:

r=10*r+x%10

The only caviats to this is that if x is negative return false or if reverse of x>INT_MAX then do the following:
Keep a conditional statement before the formula saying if(r>int_max/10 || r==int_max/10 && x%10>7)return false because even if its
palindrome it doesnt satify the fact that the number should be an integer.
*/
    bool isPalindrome(int x) {
        if(x==0)return true;
        int n=x;
        int sign=(x>0)?1:-1;
        if(sign<0)return false;
        x=abs(x);
        int r=0;
        while(x>0)
        {
            if(r>INT_MAX/10 || r==INT_MAX/10 && x%10>7)return false;
            r=r*10+x%10;
            x/=10;
        }
        return r==n;
    }
