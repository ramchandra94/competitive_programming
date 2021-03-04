// leetcode https://leetcode.com/problems/candy/

int getMin(int *arr, int n)
{
	//Write your code here
    int *output = new int[n];
    output[0] = 1;
    int result = 0;
    for(int i=1; i < n; i++){
        if(arr[i] <= arr[i-1]){
            output[i] = 1;
        }else{
            output[i] = output[i-1] + 1;
        }
    }
    
    for(int i=n-2; i >= 0; i--){
        if(arr[i] > arr[i+1]){
            if(output[i] <= output[i+1]){
                output[i] = output[i+1] + 1;
            }
        }
    }
    
    for(int i=0; i < n; i++){
        result += output[i];
    }
    return result;
}