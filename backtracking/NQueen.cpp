#include<iostream>
using namespace std;

bool isPossible(int n, int row, int col, int **board){
    // check for the same column
    for(int i=row-1; i >=0; i--){
        if(board[i][col] == 1){
            return false;
        }
    }
    
    // check upper left diagnol
    for(int i=row-1, j=col-1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    // check upper right diagnol
    for(int i=row-1, j = col + 1; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}

void helper(int n, int row, int **board){
    if(row == n){
        // we reached some solution
        // print the board 
        // return
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                cout << board[i][j] << " ";
            }
        }
        cout << "\n";
        return;
    }
    
    for(int j = 0; j < n; j++){
        if(isPossible(n, row, j, board)){
            board[row][j] = 1;
            helper(n, row+1, board);
            board[row][j] = 0;
        }
    }
    return;
}

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int **board = new int*[n];
    for(int i=0; i < n; i++){
        board[i] = new int[n];
        for(int j =0; j < n; j++){
            board[i][j] = 0;
        }
    }

    helper(n, 0, board);
}
int main(){
    placeNQueens(4);
    return 0;
}