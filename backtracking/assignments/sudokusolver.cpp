bool isPossible(int board[][9], int row, int col, int num){
    int rowFactor = row - (row%3);
    int colFactor = col - (col%3);
    for(int i=rowFactor; i <= rowFactor+2; i++){
        for(int j=colFactor; j <= colFactor+2; j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }
    
    for(int i=0; i < 9; i++){
        if(board[row][i] == num){
            return false;
        }
    }
    
    for(int i=0; i < 9; i++){
        if(board[i][col] == num){
            return false;
        }
    }
    
    return true;
}

bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
	for(int i=0; i < 9; i++){
        for(int j=0; j < 9; j++){
            if(board[i][j] == 0){
                for(int k =1; k <= 9; k++){
                    if(isPossible(board, i, j, k)){
                        board[i][j] = k;
                    	bool rec = sudokuSolver(board);
                        if(rec){
                            return true;
                        }
                        board[i][j] = 0; // if the recursion returns false revert
                    }
                }
                return false;
            }
        }
    }
    // base case where the entire grid is filled
    return true;
}
