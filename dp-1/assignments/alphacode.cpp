// leetcode problem https://leetcode.com/problems/decode-ways/
#include<iostream>
using namespace std;

#define MOD 1000000007

bool isValid(char c1, char c2){
    if(c1 == '0'){
        return false;
    }
    
    int combo = (c1 - '0')*10 + c2 - '0';
    if(combo > 26){
        return false;
    }
    return true;
}

bool isValid(char c1){
    return c1 != '0';
}

long long getResult(string input){
    long long *output = new long long[input.size()];
    output[0] = 1;
    for(int i=1; i < input.size(); i++){
		long long oneWay = 0;
        long long twoWay = 0;
        if(isValid(input[i])){
            oneWay = output[i-1];
        }
        
        if(isValid(input[i-1], input[i])){
            if(i == 1){
                twoWay = 1;
            }else{
                twoWay = output[i-2];
            }
        }
        
        long long result = ((oneWay % MOD) + (twoWay % MOD)) % MOD;
        if(result == 0){
            return 0;
        }
        output[i] = result;
    }
    return output[input.size()-1];
}

int main()
{
    while(1){
        string curr;
        cin >> curr;
        if(curr == "0"){
            break;
        }
        cout << getResult(curr) << endl;
    }
    return 0;
}
