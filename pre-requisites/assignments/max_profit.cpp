#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin >> n;
    
    int min;
    int max;
    
    cin >> min;
    max = min;
    int diff = max-min;
    
    for(int i=1; i < n; i++){
        int temp;
        cin >> temp;
        if(temp < min){
            min = temp;
        }else{
            max = temp;
            if(max-min > diff){
                diff = max-min;
            }
        }
    }
    cout << diff << endl;
    return 0;
}
