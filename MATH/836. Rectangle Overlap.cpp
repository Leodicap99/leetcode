/*
I would suggest not to use the brute force logic.Hers why:
There is another question of finding the area of the overlapped area so a common code which Im going to present to you
can be used for both questions.
In this question all we have to do is find the area and if it is greater than 0 return true:
*/
    int length(int a1,int a2,int b1,int b2)
    {
        return(min(b1,b2)-max(a1,a2));  //<-----find the linesegment that will contribute to our overlapped rectangle
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int A=rec1[0],B=rec1[1],C=rec1[2],D=rec1[3],E=rec2[0],F=rec2[1],G=rec2[2],H=rec2[3];
         long long x_dist=length(A,E,C,G);
        long long y_dist=length(B,F,D,H);
        
        if(x_dist<=0)       //<----a negative x_dist and y_dist can contribute to a positive area which should be avoided.
            x_dist=0;
        if(y_dist<=0)
            y_dist=0;
        return x_dist*y_dist>0;
    } 