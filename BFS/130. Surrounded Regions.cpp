/*
We will be using number of islands algorithm to solve this.
the algorithm goes like such

X X X X            
X O O X 
X X O X
X O X X
  |
  |
  |
  v 

X X X X
X O O X   
X X O X   <----We tamper with matrix in such a way that the order and any of its for adacent cells are made '*' if the cell contains 'O' 
X * X X

Then we do our flips

X X X X
X X X X  
X X X X
X * X X

The we change * with O

X X X X
X X X X   
X X X X
X O X X
*/
void helper(vector<vector<char>>& board,int i,int j)
    {
        if(i<0||i>board.size()-1||j<0||j>board[0].size()-1||board[i][j]=='X'||board[i][j]=='*')return;
        board[i][j]='*';
        helper(board,i-1,j);
        helper(board,i+1,j);
        helper(board,i,j-1);
        helper(board,i,j+1);
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)return;
        int rows=board.size(),cols=board[0].size();
        if(board.size()==0)return;
        for (int i=0;i<rows;i++){
            if (board[i][0] == 'O')
                helper(board,i,0);
            if (board[i][cols-1] == 'O')
                helper(board,i,cols-1);
        }
        
        for (int i=0;i<cols;i++){
            if (board[0][i] == 'O')
                helper(board,0,i);
            if (board[rows-1][i] == 'O')
                helper(board,rows-1,i);
        }
        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if (board[i][j] == '*')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                        board[i][j] = 'X';
            }
        }
    }