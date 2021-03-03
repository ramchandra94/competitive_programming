#include<bits/stdc++.h>
#include<climits>
using namespace std;
int main() {

	// Write your code here
    int n, first, second, min, max, min_cost;
    cin >> n >> first >> second;
    min = INT_MAX;
    max = INT_MIN;
    min_cost = INT_MAX;
    int *seq = new int[n];
    for(int i=0; i < n; i++){
        cin >> seq[i];
        if(seq[i] < min){
            min = seq[i];
        }
        if(seq[i] > max){
            max = seq[i];
        }
    }
    
    for(int i=min; i <=max; i++){
        int inc = 0, dec = 0;
        for(int j=0; j < n; j++){
            if(seq[j] < i){
                int diff = i - seq[j];
                inc += diff;
            }
            if(seq[j] > i){
                int diff = seq[j] - i;
                dec += diff;
            }
        }
        if(inc >= dec){
            int cost = (dec*first) + (inc-dec)*second;
            if(cost < min_cost){
                min_cost = cost;
            }
        }
    }
    cout << min_cost << endl;
    return 0;
}