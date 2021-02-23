#include<iostream>
using namespace std;

int flipIthBit(int n, int i){
    return n^(1<<i);
}
int main(){
    cout << flipIthBit(7, 2) << endl;
    return 0;
}