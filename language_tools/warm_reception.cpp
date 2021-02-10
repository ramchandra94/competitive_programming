#include<bits/stdc++.h>
using namespace std;
#include<climits>
int main() {

	// Write your code here
    int storage[2360] = {0};
    
    int n;
    cin >> n;
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i=0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp < min){
            min = temp;
        }
        storage[temp]++;
    }
    getchar();
    for(int i=0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp > max){
            max = temp;
        }
        storage[temp]--;
    }
    
    int cum_sum = 0;
    int result = 0;
    for(int i=min; i < max+1; i++){
        cum_sum += storage[i];
        if(cum_sum > result){
            result = cum_sum;
        }
    }
    cout << result << endl;
}