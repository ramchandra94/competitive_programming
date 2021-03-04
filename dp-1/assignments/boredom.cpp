// leetcode https://leetcode.com/problems/delete-and-earn/
#include<utility>
#include<climits>
using namespace std;
#include<vector>

#include<utility>
#include<climits>
using namespace std;
int solve(int n,vector<int>A){
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(n == 0){
        return 0;
    }
    int *count = new int[10001];
    
    for(int i=0; i < 10001; i++){
        count[i] = 0;
    }
    
    for(int i=0; i < n; i++){
        if(A[i] > 10000){
            return 0;
        }
        count[A[i]]++;
    }
    
    int use = 0, avoid = 0;
    int prev = -1;
    
    for(int i=1; i <= 10000; i++){
        if(count[i] > 0){
            int m = max(use, avoid);
            if(i-1 != prev){
                use = i*count[i] + m;
                avoid = m;
            }else{
                use = i*count[i] + avoid;
                avoid = m;
            }
            prev = i;
        }
    }
    
    delete count;
    return max(use, avoid);
    
    
}