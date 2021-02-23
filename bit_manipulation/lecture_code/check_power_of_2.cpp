#include<iostream>
using namespace std;

bool powerof2check(int n){
    if((n&(n-1)) == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    cout << powerof2check(4) << endl;
    cout<< powerof2check(6) << endl;
    return 0;
}