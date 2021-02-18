#include<iostream>
using namespace std;
bool isPossible(int row, int col, int maze[][20], int n, int **pathMatrix){
    if(row < 0 || col < 0 || row >= n || col >= n){
        return false;
    }
    
    if(maze[row][col] == 0 || pathMatrix[row][col] == 1){
        return false;
    }
    
    return true;
}

void helper(int maze[][20], int n, int row, int col, int **pathMatrix){
    if(row == n-1 && col == n-1){
        pathMatrix[row][col] = 1;
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                cout << pathMatrix[i][j] << " ";
            }
        }
        cout << "\n";
        pathMatrix[row][col] = 0;
        return;
    }
    
    // explore 4 paths from row, col
    
    if(isPossible(row, col-1, maze, n, pathMatrix)){
        pathMatrix[row][col] = 1;
        helper(maze, n, row, col-1, pathMatrix);
        pathMatrix[row][col] = 0;
    }
    
    if(isPossible(row-1, col, maze, n, pathMatrix)){
        pathMatrix[row][col] = 1;
        helper(maze, n, row-1, col, pathMatrix);
        pathMatrix[row][col] = 0;
    }
    
    if(isPossible(row, col+1, maze, n, pathMatrix)){
        pathMatrix[row][col] = 1;
        helper(maze, n, row, col+1, pathMatrix);
        pathMatrix[row][col] = 0;
    }
    
    if(isPossible(row+1, col, maze, n, pathMatrix)){
        pathMatrix[row][col] = 1;
        helper(maze, n, row+1, col, pathMatrix);
        pathMatrix[row][col] = 0;
    }
    return;
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */

	int **pathMatrix = new int*[n];
    for(int i=0; i <n; i++){
        pathMatrix[i] = new int[n];
        for(int j=0; j < n; j++){
            pathMatrix[i][j] = 0;
        }
    }
    
    helper(maze, n, 0, 0, pathMatrix);
    
}

int main(){
    return 0;
}