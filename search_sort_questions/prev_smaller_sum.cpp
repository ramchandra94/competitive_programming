#include<bits/stdc++.h>
using namespace std;


long long mergeSort(int *arr, int start, int end){
    if(start < end){
        int mid = start + (end-start)/2;
        long long left_count = mergeSort(arr, start, mid);
        long long right_count = mergeSort(arr, mid+1, end);
        
        int curr_length = end - start + 1;
        int *auxArr = new int[curr_length];
        
        long long *sumArr = new long long[mid-start+1];
        long long result = 0;
        sumArr[mid-start] = arr[mid];
        for(int i = mid-start-1; i >= 0; i--){
            sumArr[i] = arr[start+i] + sumArr[i+1];
        }
        
        int i = start;
        int j = mid+1;
        int k = 0;
        
        while(i <= mid && j <= end){
            if(arr[i] >= arr[j]){
                auxArr[k] = arr[i];
                i++;
            }else{
                auxArr[k] = arr[j];
                result += sumArr[i-start];
                j++;
            }
            k++;
        }
        
        while(i <= mid){
            auxArr[k] = arr[i];
            i++;
            k++;
        }
        while(j <= end){
            auxArr[k] = arr[j];
            j++;
            k++;
        }
        for(int i=0; i < curr_length; i++){
            arr[start+i] = auxArr[i];
        }
        
        delete auxArr;
        return left_count + right_count + result;
    }
    return 0;
}
int main() {

	// Write your code here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i=0; i < n; i++){
            cin >> arr[i];
        }
        long long ans = mergeSort(arr, 0, n-1);
        cout << ans << endl;
    }
}