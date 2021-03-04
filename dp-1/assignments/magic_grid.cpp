// similar to https://leetcode.com/problems/dungeon-game/
int getMinimumStrength(int** grid, int n, int m) {
	// Write your code here
    int **dp = new int*[n];
    for(int i=0; i < n; i++){
        dp[i] = new int[m];
    }
    
    dp[n-1][m-1] = 1;
    for(int i=n-2; i >= 0; i--){
        dp[i][m-1] = dp[i+1][m-1] - grid[i][m-1];
    }
    for(int i=m-2; i >= 0; i--){
        dp[n-1][i] = dp[n-1][i+1] - grid[n-1][i];
    }
    
    for(int i=n-2; i >= 0; i--){
        for(int j=m-2; j >= 0; j--){
            dp[i][j] = min(dp[i][j+1], dp[i+1][j]) - grid[i][j];
            if(dp[i][j] <= 0){
                dp[i][j] = 1;
            }
        }
    }
    
    int result = dp[0][0];
    for(int i=0; i < n; i++){
        delete dp[i];
    }
    delete dp;
    return result;
}