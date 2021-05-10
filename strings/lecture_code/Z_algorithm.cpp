#include<iostream>
#include<string>

using namespace std;

void buildZ(string text, int* Z) {
    int l = 0, r = 0;
    Z[0] = 0;
    int n = text.length();

    for(int i = 1; i < n; i++){
        if(i > r) {
            l = i;
            r = i;
            while((r < n) && (text[r-l] == text[r])){
                r++;
            }
            Z[i] = r-l;
            r--;
        }else{
            int k = i-l;
            if(Z[k] <= r - i){
                Z[i] = Z[k];
            }else{
                l = i;
                while((r < n) && (text[r-l] == text[r])){
                    r++;
                }
                Z[i] = r-l;
                r--;
            }
        }
    }
}

void searchPattern(string text, string pattern) {
    string str = pattern + "$" + text;
    int len = str.length();
    int* Z = new int[len];

    buildZ(str, Z);

    for(int i = pattern.length() + 1; i < len; i++){
        if(Z[i] == pattern.length()){
            cout << i - pattern.length() - 1 << endl;
        }
    }
    delete [] Z;
    return;
}

int main() {
    string text = "abcdsafbcdfasbcda";
    string pattern = "bcd";
    searchPattern(text, pattern);
    return 0;
}