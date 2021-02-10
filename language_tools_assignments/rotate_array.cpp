int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    
    if(a >= b){
        return gcd(b, a%b);
    }
    
    if(b > a){
        return gcd(a, b%a);
    }
}
void rotate(int *input, int d, int n)
{
    //Write your code here
    int g = gcd(n, d);
    for(int i=0; i < g; i++){
        int j = i + d;
        int k = i;
        int temp = input[i]; // temp = 1
        while(j != i){
            input[k] = input[j];
            k = j;
            j = k + d;
            if(j >= n){
                j = j - n;
            }
        }
        input[k] = temp;
    }
}