#include<iostream>
using namespace std;

int kadanes(int *arr, int n, int k){

    int prev_sum = 0;
    int best_sum = 0;
    for (int j = 0; j < k; j++)
    {
       for (int i = 0; i < n; i++)
        {
           prev_sum = prev_sum + arr[i];
            if (best_sum < prev_sum)
            {
                best_sum = prev_sum;
            }
            if (prev_sum < 0)
            {
                prev_sum = 0;
            }
        } 
    }
    
    return best_sum;
}

int main(){
    return 0;
}