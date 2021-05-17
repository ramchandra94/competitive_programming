#include<iostream>
#include<string>

using namespace std;

int lps(string s) {
    int n = s.length();
    int max = 0;

    for(int i=0; i < n; i++){
        int curr = 1;
        // odd flow
        int p1 = i-1;
        int p2 = i+1;
        while(p1 >= 0 && p2 < n && s[p1] == s[p2]) {
            p1--;
            p2++;
        }
        curr = p2-p1-1;
        if(curr > max) {
            max = curr;
        }
        // even flow
        if(s[i] == s[i+1]) {
            p1 = i-1;
            p2 = i+2;
            while(p1 >= 0 && p2 < n && s[p1] == s[p2]) {
                p1--;
                p2++;
            }
            curr = p2-p1-1;
            if(curr > max) {
                max = curr;
            }
        }
    }
    return max;
}
int main() {
    string s;
    cin >> s;
    cout << lps(s) << endl;
    return 0;
}