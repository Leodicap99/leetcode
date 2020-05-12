/*
Note that u are starting from the bottom and u change the direction after finishing every row.
Approach used here is BFS.
We push the start(1) to our queue and proceed with our BFS.
We will explore all the six sides and keep moving forward until I reach r*r where r is the size of the board.

Apart from the standard BFS performed here the only tricky part is to find the next step u are going to take becaue of the direction given in question is pretty hard.

Note that if ur board is a 6x6 board ur start which is 1 will be (5,0) 5 denoting the last row and 0 denoting the first column.
But another problem arises aprat fromt this,

          7<------Note that after 6 the direction reverses itself and we should be able to tackle this too.
1 2 3 4 5 6

Lets try tackling these two conditions namely:-
1. We must be able to go bottom to top.
2. We must be able to flip our direction after every row.

Algorithm:-
Its not exactly an algorithm but a simple formula to tackle this.

1.Our row traversal must go like this- 5,4,3,2,1  5(fromt 1 to 6),4(from 7 to 12) and so on....

So the way to go about it is we divide the number we are at by the board size and u get a number. You subtract the board size with that number and by 1 cuz we start from 0.
Let me explain

Let num=1
1/6=0
6-0-1=5<-- this is the row we are at
This will work for 1,2,3,4,5 but not for 6
6/6=1
6-1-1=4 but we are still at row 5
So the way to tackle this is by using this
int x=(next_step-1)/row;
x=row-1-x;
This will make 1,2,3,4,5,6 all in the same row.
column is easy all u have to do is int y=(next_step-1)%row;


2. For fliping direction all we are going to dow is we have found x in the previous step.
   so for every odd x we flip the direction and for every even ir we maintain our normal direction.
   if(x%2==1)if(x%2==1)y=row-1-y;

*/
    vector<int> calc(int row,int next_step)
    {
        int x=(next_step-1)/row;
        int y=(next_step-1)%row;
        if(x%2==1)y=row-1-y;
        x=row-1-x;
        return {x,y};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int r=board.size();
        queue<int> q;
        q.push(1);
        int step=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int t=q.front();
                q.pop();
                if(t==r*r)return step;
                for(int i=1;i<=6;i++)
                {
                    int next_step=t+i;
                    if(next_step>r*r)break;
                    auto v=calc(r,next_step); 
                    int row=v[0],col=v[1];
                    if(board[row][col]!=-1)
                    {
                        next_step=board[row][col];
                    }
                    if(board[row][col]!=r*r+1)
                    {
                        q.push(next_step);
                        board[row][col]=r*r+1;
                    }
                }
            }
            step++;
        }
        return -1;
    }
