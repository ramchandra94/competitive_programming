#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        long prod[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long lp =1;
        for (int i = 0; i < n; i++)
        {
            prod[i] = lp;
            lp = lp * arr[i];
        }
        long rp = 1;
        for(int i=n-1; i >=0; i--){
            prod[i] = prod[i]*i;
            rp = rp*arr[i];
        }
        for(int i=0; i < n; i++){
            cout << prod[i] << " ";
        }
        cout << "\n";
    }
    
}