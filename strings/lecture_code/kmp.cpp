#include<iostream>
#include<string>

using namespace std;

int *getLPS(string pattern) {
    int len = pattern.length();
    int *lps = new int[len];
    lps[0] = 0;
    int i = 1, j = 0;

    while(i < len){
        if(pattern[i] == pattern[j]){
            lps[i] =  j + 1;
            i++; j++;
        } else {
            if( j != 0){
                j = lps[j-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool kmp(string text, string pattern) {
    int *lps = getLPS(pattern);
    int i = 0, j = 0;

    while (i < text.length() && j < pattern.length())
    {
        if(text[i] == pattern[j]){
            i++; j++;
        } else {
            if(j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }

    if(j == pattern.length()){
        return true;
    }

    return false;

}

int main() {
    string text = "abcxabcdabcdabcy";
    string pattern = "abcdabcy";
    cout << kmp(text, pattern) << endl;
    return 0;
}