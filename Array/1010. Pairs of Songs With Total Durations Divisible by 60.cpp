/*
This problem is like 2 sum with a twist.
We are going to use a map to store the a number so when a number + mapped number gives 60 we can increment our answer.
I will be explaining with the code :-
*/
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans=0;
        unordered_map<int,int> map;
          for (int &t : time) {
            ans += map[(60 - t % 60) % 60];
             ++map[t % 60];
          }
        return ans;
    }
/*
Let Input: [30,20,150,100,40]

Bsically we are scaling all the inputs in the order of mod 60 So we find wo inputs whose sum is equal to 60.
(60 - t % 60) % 60 this value check if for t 60-t exist or not if so increment ur answer.