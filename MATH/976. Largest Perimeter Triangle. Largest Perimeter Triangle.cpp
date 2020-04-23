/*Lets learn the basics of triangle
according to the triangle inequality
for a triangle to exist->sum of lengths of two sides must be greater than the 3rd side.
NOTE:It will be equal to the 3rd side when the area is 0.
          /\ 
     4   /  \  3
        /    \
        ------
          5
 in this case sum of any two sides is greater than or equal to the 3rd side.
 Thus as we get want the largest area the last 3 sides of the array would give us thee answer
 provided it follows the inequality property.
 so what we do is sort it in the decreasing order and take 3 elements and check for the inequality.
 let me demonstrate
 Input: [3,6,2,3]
 we sort it first in decreasing order
        [6,3,3,2]
  we keep taking 3 elements from the start and keep checking
  as soon as it satisfies we break from the loop and return the answer.
  here the first 3 elements are [6,3,3]
  but 3+3=6 which is a triangle with 0 area so it is discarded.
  next is [3,3,2] which satisfies the inequality.
  thus the perimeter is 3+3+2=9
   */
    int largestPerimeter(vector<int>& A) {
        if(A.size()<3)return 0;
        int per=0;
        sort(A.rbegin(),A.rend());
        for(int i=0;i<A.size()-2;i++)
        {
            if(A[i]>=A[i+1]+A[i+2])continue;
            else
            {
                per=A[i]+A[i+1]+A[i+2];
                break;
            }
        }
        return per;
    }
