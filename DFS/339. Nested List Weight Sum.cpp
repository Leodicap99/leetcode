/*
If the element is an integer we and th product of that integer and depth.
Else we do do dfs with an incremented depth by calling the List function.

eg:-[1,[4,[6]]]
Intinially I call a dfs function with vector and depth=1.
As the element is an integer we just add the product of the integer with depth.
sum=1

As the second element is a List we will call the List function dfs(nestedList[i].getList(),depth+1)

|       |
|       |
|       |          <------recursion Stack
|[4,[6]]| 

We start by checking if the first element is an integer as it is an Integer we add it to our sum

sum = sum + integer*depth = 1+4*2=9

As the second element is a list we call dfs

|       |
|       |
| [6]   |          <------recursion Stack
|[4,[6]]| 

We start by checking if the first element is an integer as it is an Integer we add it to our sum

sum = sum + integer*depth =9 + 6*3=27

*/

    int dfs(vector<NestedInteger>& nestedList,int depth)
    {
        int n=nestedList.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            if(nestedList[i].isInteger())
                sum+=nestedList[i].getInteger()*depth;
            else 
                sum+=dfs(nestedList[i].getList(),depth+1);
        }
        return sum;
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList,1);
    }