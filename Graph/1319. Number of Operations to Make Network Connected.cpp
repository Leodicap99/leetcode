/*
The questions asks us to find the number of disconnected components in the graph but with one caveat:- That if the number of extra edges
is lesser than components-1 then return -1.
Why components-1?
Because 1 component belongs to the connected graph and the other remains a forest.

The way to solve this is have a group array that assigns each member into a group.
While traversing connections if they are from different groups merge them.
If they are not from different groups that means it is an extra edge 
Finally calculate the number of components(no. of elements within each group) and check the caveat and retuen the answer accordingly.
*/

    int find(int x,vector<int> &parent)
    {
        return parent[x]==x?x:find(parent[x],parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> groups(n);
        for(int i=0;i<n;i++)
            groups[i]=i;
        int extraedges=0;
        for(auto &x:connections)
        {
            int group1=find(x[0],groups);
            int group2=find(x[1],groups);
            if(group1!=group2)
            {
                groups[group2]=group1;
            }
            else extraedges++;
        }
        int components=0;
        for(int i=0;i<n;i++)if(groups[i]==i)components++;
        return (extraedges>=components-1)?components-1:-1;
    }