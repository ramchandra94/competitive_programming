#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

char getChar(int i){
    return (char)(i+97);
}
void printPalindromeString(string s){
    unordered_map<char, vector<int> > map;
    for(int i=0; i < s.length(); i++){
        map[s[i]].push_back(i);
    }
    int odd_freq_count = 0;
    for(int i=0; i < 26; i++){
        if((map[getChar(i)].size() % 2) != 0){
            odd_freq_count++;
        }
    }
    if(odd_freq_count >= 2){
        cout << -1 << endl;
        return;
    }

    int ans[s.length()];
    int start = 0;
    int end = s.length()-1;
    for(int i=0; i < 26; i++){
        char currentChar = getChar(i);
        for(int j=0; j < map[currentChar].size(); j += 2){
            if((map[currentChar].size() - j) == 1){
                ans[s.length()/2] = map[currentChar][j];
                continue;
            }
            ans[start] =  map[currentChar][j];
            ans[end] = map[currentChar][j+1];
            start++;
            end--;
        }
    }
    for(int i=0; i < s.length(); i++){
        cout << ans[i] + 1;
    }
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        printPalindromeString(s);
        cout << endl;
    }
    return 0;
}