/*
we are goin to use the reverse() stl to solve this problem
we are goin to solve this in place with no extra string.
for every 1 =0,2k,4k,.... we will reverse the string from i to i+k
As per the question if i+k<size just reverse the remaining characters.
*/
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=2*k)reverse(s.begin()+i,min(s.begin()+i+k,s.end()));
        return s;
    }
