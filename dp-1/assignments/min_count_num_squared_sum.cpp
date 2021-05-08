int minCount(int n)
{
	//Write your code here
    int *output = new int[n+1];
    output[0] = 0;
    
    for(int i=1; i <= n; i++){
        int minimum = i;
        for(int j=1; j <= i; j++){
            if((j*j) <= i){
                int remaining = i - (j*j);
                int curr = 1 + output[remaining];
                if(curr < minimum){
                    minimum = curr;
                }
            }
        }
        output[i] = minimum;
    }
    
    return output[n];
}