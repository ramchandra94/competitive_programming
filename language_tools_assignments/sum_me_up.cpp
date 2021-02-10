#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int t;
    cin >> t;
    while(t--){
        long long int input;
        cin >> input;
        int sum = 0;
        while(input > 0){
            sum = sum + input % 10;
            input = input/10;
        }
        cout << sum << endl;
    }
}