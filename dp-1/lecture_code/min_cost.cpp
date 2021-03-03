#include<iostream>
#include<climits>
using namespace std;

int min_cost(int **input, int m, int n){
    int **dp = new int*[m];
    for(int i=0; i < m; i++){
        dp[i] = new int[n];
    }
    dp[m-1][n-1] = input[m-1][n-1];
    for(int i=m-2; i >=0; i--){
        dp[i][n-1] = dp[i+1][n-1];
    }
    for(int i=n-2; i >= 0; i--){
        dp[m-1][i] = dp[m-1][i+1];
    }
    for(int i=m-2; i >= 0; i--){
        for(int j=n-2; j >= 0; j--){
            dp[i][j] = min(dp[i+1][j+1], dp[i+1][j], dp[i][j+1]);
        }
    }
    for(int i=0; i < m; i++){
        delete dp[i];
    }
    delete dp;
    int result = dp[0][0];
    return result;
}
int main(){
    int **input = new int*[3];
    input[0] = new int[3];
    input[1] = new int[3];
    input[2] = new int[3];

    input[0][0] = 4;
    input[0][1] = 3;
    input[0][2] = 2;
    input[1][0] = 1;
    input[1][1] = 8;
    input[1][2] = 3;
    input[2][0] = 1;
    input[2][1] = 1;
    input[2][2] = 8;

    cout << min_cost(input, 3, 3) << endl;

    delete input[0];
    delete input[1];
    delete input[2];
    delete input;
}