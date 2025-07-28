/*
Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves are allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Implement the TicTacToe class:

TicTacToe(int n) Initializes the object the size of the board n.
int move(int row, int col, int player) Indicates that the player with id player plays at the cell (row, col) of the board. The move is guaranteed to be a valid move, and the two players alternate in making moves. Return
0 if there is no winner after the move,
1 if player 1 is the winner after the move, or
2 if player 2 is the winner after the move.
*/
class TicTacToe {
    vector<int>r,c;
    int dg,adg,n;
public:
    TicTacToe(int n) {
        r.assign(n,0);
        c.assign(n,0);
        dg=adg=0;
        this->n=n;
    }
    
    int move(int row, int col, int player) {
        int cur=(player==1)?1:-1;
        r[row]+=cur;
        c[col]+=cur;
        if(row==col){
            //diagonal
            dg+=cur;
        }
        if(col==(n-row-1)){
            //anti-diagonal
            adg+=cur;
        }
        if(abs(r[row])==n || abs(c[col])==n || abs(dg)==n || abs(adg)==n){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
