#include<algorithm>

int countPair(int *arr, int n, int start, int pair_sum){
    int j = start + 1, k = n-1, count =0;
    while(j < k){
        if(arr[j]+arr[k] == pair_sum){
            int low_count = 0;
            int temp = j;
            while(temp <= k && arr[temp] == arr[j]){
                low_count++;
                temp++;
            }
            int high_count = 0;
            temp = k;
            while(temp >= j && arr[temp] == arr[k]){
                high_count++;
                temp--;
            }
            if(arr[j]==arr[k]){
                count = count + (low_count*(high_count-1))/2;
            }else{
                count = count + low_count*high_count;
            }
            j = j + low_count;
            k = k - high_count;
        } else if(arr[j]+arr[k] > pair_sum){
            k--;
        } else{
            j++;
        }
    }
    return count;
}

int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    sort(arr, arr+n);
    int count = 0;
    for(int i=0; i < n-2; i++){
        int pair_sum = num -arr[i];
        count = count + countPair(arr, n, i, pair_sum);
    }
    return count;
    
}