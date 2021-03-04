// similar to https://leetcode.com/problems/house-robber/
#include<iostream>
#include<utility>
#include<climits>
#include<vector>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    vector<pair<int, int>> output(n, std::make_pair(0, 0));
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return arr[0];
    }
    if(n == 2){
        return max(arr[0], arr[1]);
    }
    int globMax = INT_MIN;
    output[0].first = arr[0];
    output[0].second = 0;
    
    output[1].first = arr[1];
    output[1].second = arr[0];
    
    for(int i=2; i < n; i++){
        output[i].first = arr[i] + max(output[i-2].first, output[i-2].second);
        output[i].second = max(output[i-1].first, output[i-1].second);
        if(output[i].first > globMax){
            globMax = output[i].first;
        }
        if(output[i].second > globMax){
            globMax = output[i].second;
        }
    }
    return globMax;
}
int main(){
    return 0;
}