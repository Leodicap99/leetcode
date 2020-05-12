/*
This actually a pretty naive dp solution.
U just implement the definition of dp and u ll get the answer.
Dynamic Programming is mainly an optimization over plain recursion. We will just use it to store values in an array.
By the way i wont be using recursionI found a simpler way to do it :-
*/
    int knightDialer(int N) {
        if(N==1)return 10;
        long mod = 1000000007;
        vector<long> prev(10,1),curr(10,0);
        while(--N)
        {
            curr[0]=(prev[4]+prev[6])%mod;         //These are the possible locations i can reach from 0
            curr[1]=(prev[6]+prev[8])%mod;
            curr[2]=(prev[7]+prev[9])%mod;
            curr[3]=(prev[4]+prev[8])%mod;
            curr[4]=(prev[9]+prev[0]+prev[3])%mod;
            curr[6]=(prev[1]+prev[7]+prev[0])%mod;
            curr[7]=(prev[6]+prev[2])%mod;
            curr[8]=(prev[1]+prev[3])%mod;
            curr[9]=(prev[2]+prev[4])%mod;
            for(int i=0;i<10;i++)prev[i]=curr[i];      //As N keeps decrementing we update the array to keep track of the steps we take
        } 
        long sum=0;
        for(int i=0;i<10;i++)
            sum=(sum+curr[i])%mod;
        return (int)sum;
    }