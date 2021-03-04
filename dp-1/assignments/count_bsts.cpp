// leetcode link https://leetcode.com/problems/unique-binary-search-trees/

int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int *output = new int[n+1];
    long long mod = 1000000007;
    output[0] = 1;
    
    for(int i=1; i <= n; i++){
        long long ans = 0;
        for(int k=0; k < i; k++){
            long long temp = ((output[k] % mod)*(output[i-1-k] % mod)) % mod;
            ans = ((ans % mod) + (temp % mod)) % mod;
        }
        output[i] = ans;
    }
	
    int ans = output[n];
    delete output;
    return ans;
}
