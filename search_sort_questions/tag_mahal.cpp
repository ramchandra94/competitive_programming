#include<bits/stdc++.h>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    int min = INT_MAX;
    int min_index;
    for(int i=0; i < n; i++){
        int size;
        cin >> size;
        int t;
        if(size < i){
            t = 0;
        } else{
            t = (size-i)/n;
            if((size-i) % n != 0){
                t = t+1;
            }
        }
        if(i + (t*n) < min){
            min = i + (t*n);
            min_index = i;
        }
    }
    cout << min_index + 1 << endl;
	return 0;
}
