#include<iostream>
#include<string>
using namespace std;

#define N 9

bool findEmptyLocation(int grid[N][N], int &row, int &col){
    for(int i=0; i < N; i++){
        for(int j =0; j < N; j++){
            if(grid[i][j] == 0){
                return true;
            }
        }
    }
    return false;
}

bool isSafeRow(int grid[N][N], int row, int num){
    for(int i=0; i < N; i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    return true;
}

bool isSafeCol(int grid[N][N], int col, int num){
    for(int i=0; i < N; i++){
        if(grid[i][col] == num){
            return false;
        }
    }
    return true;
}

bool isSafeBox(int grid[N][N], int row, int col, int num){
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for(int i=0; i <= 2; i++){
        for(int j=0; j <= 2; j++){
            if(grid[rowFactor + i][colFactor + j] == num){
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int grid[N][N], int row, int col, int num)
{
    isSafeRow(grid, row, num) && isSafeCol(grid, col, num) && isSafeBox(grid, row, col, num);
}
bool solveSudoku(int grid[N][N]){
    int row, col;
    if(!findEmptyLocation(grid, row, col)){
        return true;
    }

    for(int i=1; i <=9; i++){
        if(isSafe(grid, row, col, i)){
            grid[row][col] = i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}
int main(){
    int grid[N][N];
    for(int i=0; i < N; i++){
        string s;
        cin >> s;
        for(int j=0; j < n; j++){
            grid[i][j] = s[j] - '0';
        }
    }

    solveSudoku(grid);

    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }





    return 0;
}