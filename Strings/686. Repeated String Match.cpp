class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for(int i=0,j=0;i<A.size();i++)
        {
            for(j=0;j<B.size() && A[(i+j)%A.size()]==B[j];j++);
            if(j==B.size())
                return (i+j-1)/A.size()+1;
        }
        return -1;
    }
};
