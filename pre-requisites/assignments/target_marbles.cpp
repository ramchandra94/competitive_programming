#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i < n/2; i++){
        int total = arr[i] + arr[n-i-1];
        int remainder = total % 10;
        cout << total/10 << " " << remainder << endl;
    }
	return 0;
}
