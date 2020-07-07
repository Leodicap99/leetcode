class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal,antidiagonal,n;
    TicTacToe(int size) {
        n=size;
        diagonal=0,antidiagonal=0;
        rows.resize(n),cols.resize(n);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int toadd=player==1?1:-1;
        rows[row]+=toadd;
        cols[col]+=toadd;
        if(row==col)diagonal+=toadd;
        if(col==(n-row-1))antidiagonal+=toadd;
        if(abs(rows[row])==n||abs(cols[col])==n||abs(diagonal)==n||abs(antidiagonal)==n)return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
