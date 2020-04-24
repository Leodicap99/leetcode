/*The bruteforce solution to this problem would be to initialize x=1 and & x from m to n.
While this is efficient we can do better using some bit logic.
Lets take two nubers
m = 1000010010110
n = 1000101011011
so this is the range givven to us.
We kniw that even one 0 is present it can  make the whole result 0.
As this is a range given here in m and n whatever it is the first 4 digits from the left will be the same 
whatsoever ans the rest will be 0s as there will be atleast 1 0.
So we can leverage this fact and decrease our original complexity to logarithmic.
we rightshift m and n unti they are equal and right shift if by the sam amount as the above logic mentioned
all the other eements will be 0.

*/
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(m!=n)
        {
            m>>=1;   //<------right shifting
            n>>=1;
            i++;
        }
        return m<<i;
    } 
