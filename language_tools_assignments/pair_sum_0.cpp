#include<unordered_map>

int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> map;
    int count = 0;
    for(int i=0; i < n; i++){
        int temp = 0 - arr[i];
        if(map.count(temp) > 0){
            count += map.at(temp);
        }
        if(map.count(arr[i]) > 0){
            map[arr[i]] += 1;
        }
        else{
            map.insert({arr[i], 1});
        }
    }
    return count;
}