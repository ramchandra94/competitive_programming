int helper(int denominations[], int numDenominations, int value, int **output){
    if(value == 0){
        return 1;
    }
    if(numDenominations == 0){
        return 0;
    }
    if(value < 0){
        return 0;
    }
    int first;
    if(value >= denominations[0] && output[value-denominations[0]][numDenominations] != -1){
        first = output[value-denominations[0]][numDenominations];
    }else{
        first = helper(denominations, numDenominations, value-denominations[0], output);
    }
    int second;
    if(output[value][numDenominations-1] != -1){
        second = output[value][numDenominations-1];
    }else{
        second = helper(denominations+1, numDenominations-1, value, output);
    }
    output[value][numDenominations] = first + second;
    return first+second;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
    int **output = new int*[value+1];
    for(int i=0; i < value+1; i++){
        output[i] = new int[numDenominations+1];
        for(int j=0; j < numDenominations+1; j++){
            output[i][j] = -1;
         }
    }
    return helper(denominations, numDenominations, value, output);
}