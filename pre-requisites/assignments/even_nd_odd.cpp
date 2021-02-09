#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int even = 0;
    int odd = 0;
    for(int i=0; i < n; i++){
        int curr;
        cin >> curr;
        if((curr % 2 == 0) && (i % 2 == 0)){
            even += curr;
        }
        
        if((curr % 2 != 0) && (i % 2 != 0)){
            odd += curr;
        }
    }
    
    cout << even << " " << odd;
	return 0;
}
