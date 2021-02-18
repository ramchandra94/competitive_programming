#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i=0; i < n; i++){
            cin >> arr[i];
        }
        
        bool flag = true;
        
        for(int i=0; i < n; i++){
            if(arr[i] != i && arr[i+1] != arr[i] -1){
                flag = false;
                break;
            }else{
                if(arr[i] != i){
                    swap(arr[i], arr[i+1]);
                }
            }
        }
        
        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        
    }
	return 0;
}
