We will be trying to attack this question by using an inplace algorithm.
Although using an auxilliary array will work its not space efficient.
We will place two pointers at the start lets say l and r.
We will try to make l point to an odd value and r to an even value and we swap.
array =  2 5 3 7
         ^
         |
        l,r

Since l is pointing to an even value it swaps with the right pointer and increments itself.

array =  2 5 3 8
         ^ ^
         | |
         r l
then right poiter increments as usual and we reach 8.
Since 8 is an even number we swap it with left and incement left ponter.

array =  2 8 5 3

   vector<int> sortArrayByParity(vector<int> &A) {
        int l=0,r=0;
       while(r<A.size())
       {
           if(A[r]%2==0)swap(A[l++],A[r]);
           r++;
       }
       return A;
    }
