#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int i, p;
        cin >> i >> p;
        int ans = i + p;
        if(ans >= 12){
            ans = ans - 12;
        }
        cout << ans << endl;
    }
	return 0;
}
