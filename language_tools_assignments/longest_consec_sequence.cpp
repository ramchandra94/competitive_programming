#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int, pair<int, bool> > map;
    vector<int> result;
    for(int i=0; i < n; i++){
        map.insert({arr[i], {i, true}});
    }
    
    int best_length = 0;
    int best_index;
    int min;
    for(int i=0; i < n; i++){
        if(map.at(arr[i]).second){
            int left_count = 0;
            int start = arr[i]-1;
            int l_index = i;
            int curr_min = arr[i];
            while(true){
                if(map.count(start) > 0){
                    l_index = map.at(start).first;
                    curr_min = start;
                    left_count++;
                    start--;
                }else{
                    break;
                }
            }
            int right_count = 0;
            start = arr[i] + 1;
            while(true){
                if(map.count(start) > 0){
                    right_count++;
                    start++;
                }else{
                    break;
                }
            }
            int total_count = left_count + right_count + 1;
            if(total_count > best_length){
                best_length = total_count;
                best_index = l_index;
                min = curr_min;
            }
            if(total_count == best_length){
                if(l_index < best_index){
                    best_index = l_index;
                    min = curr_min;
                }
            }
        }
    }
    result.push_back(min);
    result.push_back(min + best_length -1);
    return result;
}