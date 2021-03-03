#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    long long num_groups = 0;
    
    for(int i=0; i < n; i++){
        if(s[i] == '0'){
            num_groups++;
            while(i < n && s[i]=='0'){
                i++;
            }
        }
    }
    if(num_groups == 0){
        cout << 0 << endl;
    }else{
        long long cost = (num_groups-1)*min(x, y) + y;
        cout << cost << endl;
    }
	return 0;
}