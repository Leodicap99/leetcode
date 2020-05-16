/*
The reason why u see many solutions in union find is using this data structure is not only efficient in terms of speed but also very easy to implement
I suggest William Fiset youtube lecture on Union find.
The way to solve this problem is to first initialze the number of groups is n(All are friends of itself only).    
Then we start merging groups of whose friendship is explained in terms of matrix.
 _            _
|   1   1   0  |
|              |
|   1   1   0  |
|              |
|_  0   0   1 _|

This means that friend 0 is friends with (0,1)
frinds 1 is friend with (0,1)
friends 2 is friend with itself(2)
count=3
Lets start using the merging principle and merge friends to their respective groups
We have a group array which each index is mapped to a group 

[0,1,2] <---Groups
 0 1 2 <---friends

As friend 1 is  a friend of friend 0 we will map them to the same parent. It can be of any choice either 0 or 1
[0,0,2] <---Groups
 0 1 2 <---friends
  count-- = 2
 After this merge we come to know that 1 and 0 are unioned together froming a group.
 As 2 is friend to itself and no one else we dont do anything .
 
 We return the count which is 2
 */
    int find(int x,vector<int> &parents)
    {
        return parents[x]==x?x:find(parents[x],parents);
    }
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size()==0)return 0;
        int n=M.size();
        vector<int> groups(n,0);
        int count=n;
        for(int i=0;i<n;i++)groups[i]=i;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(M[i][j])
                {
                    int group1=find(i,groups);
                    int group2=find(j,groups);
                    if(group1!=group2)
                    {
                        groups[group1]=group2;
                        count--;
                    }
                }
            }
        }
        return count;
    }
