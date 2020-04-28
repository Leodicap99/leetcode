/*
We will be using a hash table approach to solve this.
Firstly to tackle this we will be needing to store the last index of each character to help us find the segment which have characters
different from the other segment.
Next we will be attacking the heart of the question.
We will iterate i through the array and keep storing the maxindex if i hits the maxindex that means that the characters in
this segment will not repeat anywhere after this.

let S = "ababcbacadefegdehijhklij"

map 
a->8
b->5
c->7
d->14 
e->15
f->11
g->13
h->19
i->22
j->23
k->20
l->21


so when we start our maxindex=0 and last index=0
maxindex =8 because of a
max index wont change because of b as bs last index is 5
max index wont change because of c 
thus when i reaches 8 it has hit the max index thus we have got our first segment (maxindex-lastindex+1)
now we update last index to 9 and we follow the same procedure
now maxindex and i would be same at 15 thus the segment size will be maxindex-lastindex+1=7
and similarly the last segement will be of size 8

*/
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> map;
        vector<int> ans;
        if(S.size()==0)return ans;
        for(int i=0;i<S.size();i++)
            map[S[i]]=i;
        int maxindex=0,lastindex=0;
        for(int i=0;i<S.size();i++)
        {
            maxindex=max(maxindex,map[S[i]]);
            if(i==maxindex)
            {
                ans.push_back(maxindex-lastindex+1);
                lastindex=i+1;
            }
        }
        return ans;
    }
