#include<iostream>
using namespace std;

bool checkIthBit(int n, int i){
    if(n&(1 << i) == 0){
        return false;
    }else{
        return true;
    }
}
int main(){
    int number = 10;
    int i = 3;
    checkIthBit(number, i);
    return 0;
}