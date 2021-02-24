// code forces equalize problem
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cost = 0;
    
    for(int i=0; i < n;){
        if(s[i] != t[i]){
            // either swap or flip
            if(i+1 < n && s[i] != s[i+1] && s[i+1] != t[i+1]){
                i = i + 2;
            }
            else{
                i++;
            }
            cost++;
        }
        else{
            i++;
        }
    }

    return 0;
}