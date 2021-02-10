int findUnique(int *arr, int n) {
    // Write your code here
    int result = 0;
    for(int i=0; i < n; i++){
        result = result ^ arr[i];
    }
    
    return result;
}