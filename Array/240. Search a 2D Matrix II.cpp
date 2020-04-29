/*
The way to solve this using o(n) time(to be accurate o(n+m)) is to think of binary search.
Whenever a question says sorted it screams binary search.
But how do we use binary search?
One way to do this to use binary search on every row and find the target element.
This is a really good solution with o(n*log(m)) complexity we can do better

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

we can notice that the matrix is sortd 2 ways rowwise and column wise, How can that help us?
Lets break it down if a number if greater than a target what do u do? we usually move the left pointer towards right
So if we were to be in the first row and the target is greater than the last element in that row as the matrix is column wise
sorted too it would make sense for us to go down the matrix

Let the target be 6
let us begin by keeping our pointer at right most corner and a pointer at the start of the matrix.
   row
   |
[  v
  [1,   4,  7, 11, 15],<----col
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
the target is lesser than matrix[row][col] so it would make sense to decrement the col pointer

11>6 so again decrement 
This process continues until the coll pointer points to 4
now since target ifs greater increment the col pointer
notice that col pointer will never go reverse because of the multidimensional sorting preoperty.
as matrix[row][col] =5<target increment col
and we reach 6.

Why doesnt the col increment ?

Lets consider the smae example as before 
what if 6 were to be present in 2 row and no the 3rd:

[
  [1,   4,  7, 11, 15],
  [2,   5,  6, 12, 19],<---6 is present here now
  [3,   7,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
If this was the case our algorithm woyldnt have worked since once we hit 4 all we have is row++ or col-- we would never reach 6
But this disobeys what the q says that is columns also must be srted if u notice col=2 is not sorted.
*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)return false;
        int n=matrix.size(),m=matrix[0].size();
        int row=0,col=m-1;
        while(row<n&&col>=0)
        {
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]<target)row++;
            else col--;
        }
        return false;
    }