int totalSum(int **input, int n)
{
    //Write your code here
    int sum = 0;
    for(int i=0; i < n; i++){
        sum += input[0][i];
    }
    for(int i=1; i < n; i++){
        sum += input[i][n-1];
    }
    for(int i=n-2; i >= 0; i--){
        sum += input[n-1][i];
    }
    for(int i=n-2; i >= 1; i--){
        sum += input[i][0];
    }
    
    for(int i=1; i < n-1; i++){
        sum += input[i][i];
        if(i != n-1-i){
            sum += input[i][n-1-i];
        }
    }
    
    return sum;
}