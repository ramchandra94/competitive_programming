#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
    
    int swaps = 0;
    bool flag = true;
    for(int i=0; i < n; i++){
        if((arr[i] < i - 1) || (arr[i] > i + 3)){
            cout << "NO" << endl;
            flag = false;
            break;
        }
        int diff = (arr[i]-1) - i;
        if(diff < 0){
            diff = diff *-1;
        }
        swaps += diff;
    }
    
    if(flag){
        cout << "YES" << endl;
    	cout << swaps/2 << endl;
    }
    return 0;
}