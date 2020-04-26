We first keep incrementing i if it encounter whitespaces.
After this the next character can be either a sign or an integer.Remember once u enter this territory whitesace are not allowed.
The only difficult part in this problem is to handle the corner cases of numbers exceeding INT+MAX or MIN.
what we do is after finishing up on all the whitespaces and sign initialization we put a while loop allowing character from 0 to 9
inclusive only. In there befire calculating the base value we try to handle the corner case.Why?
Because base is calculated by the formula = base=base*10+str[i] so if it has crossed INT_MAX it will throw an error because ur base which is 
int value will only accept int values.
So we check if base>INT_MAX/10.But there should be another thing hat has to be handled.

Let str = "   +2147483648"

So according to our logic the pointer will skip all the whitespaces reaching '+'sign and will initialize the sign of our base.
 CAVIAT:number is greater that INT_MAX/10 or equal to INT_MAX/10 and str[i]-'0'>7
Now we enter the heart of the program. We first check our base if CAVIAT since our base value is intialized to 0 the caclulation 
proceeds as such:

base=base*10+(str[i]-'0') = 2

Check CAVIAT = false

base=base*10+(str[i]-'0') = 21

base=base*10+(str[i]-'0') = 214

Check CAVIAT = false
base=base*10+(str[i]-'0') = 2147

Check CAVIAT = false
base=base*10+(str[i]-'0') = 21478

Check CAVIAT = false
base=base*10+(str[i]-'0') = 214783

Check CAVIAT = false
base=base*10+(str[i]-'0') = 214783

Check CAVIAT = false
base=base*10+(str[i]-'0') = 2147836

Check CAVIAT = false
base=base*10+(str[i]-'0') = 21478364

Check CAVIAT = true Since base value==INT_MAX/10 and str[i] == 8>7
Thus we return INT_MAX or INT_MIN according to the sign

Remember that this will work if str = "   -2147483648" though the caviat is true cuz it checks the sign and return INT_MIN.

    int myAtoi(string str) {
        int sign=1,base=0;
        int i=0;
        while(str[i]==' ')i++;
        if(str[i]=='-'||str[i]=='+')
        {
            sign=1-2*(str[i]=='-');
            i++;
        }
        while(str[i]>='0'&&str[i]<='9')
        {
            if(base>INT_MAX/10||base==INT_MAX/10&&str[i]-'0'>7)
            {
                if(sign==1)return INT_MAX;
                else
                    return INT_MIN;
            }
            base=base*10+(str[i++]-'0');
        }
        return base*sign;
    }