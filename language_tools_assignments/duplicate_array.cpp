#include<iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    for(int i =0; i < n; i++){
        if(arr[i] == 0){
            if(arr[n-1] < 0 || arr[n-1]== 0){
                return 0;
            }
            arr[n-1] *= -1;
        }
        if(arr[abs(arr[i])] < 0){
            return abs(arr[i]);
        }
        arr[abs(arr[i])] *= -1;
    }
}