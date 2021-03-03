// leetcode 1671

#include<utility>
#include<vector>
int longestBitonicSubarray(int *input, int n) {
    
    /* Don't write main().
    * the input is already passed as function argument.
    * Taking input and printing output is handled automatically.
    */
    
    vector<pair<int, int> > arr (n, std::make_pair(0, 0));
    int globMax = 0;
    for(int i=0; i < n; i++){
        int inc = 1, dec = 1;
        for(int j=i; j >=0; j--){
            if(input[i] < input[j]){
                int temp = max(arr[j].first, arr[j].second) + 1;
                if(temp > dec){
                    dec = temp;
                }
            }
            else if(input[i] == input[j]){
                int temp = arr[j].first;
                if(temp > inc){
                    inc = temp;
                }
            }
            else{
                int temp = arr[j].first + 1;
                if(temp > inc){
                    inc = temp;
                }
            }
        }
        arr[i] = std::make_pair(inc, dec);
        if(inc > globMax){
            globMax = inc;
        }
        if(dec > globMax){
            globMax = dec;
        }
    }
    return globMax;
    
}