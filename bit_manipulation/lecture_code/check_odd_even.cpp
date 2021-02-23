#include<iostream>
#include<string>
using namespace std;

string check(int n){
    if((n&1) == 0){
        return "even";
    }else{
        return "odd";
    }
}
int main(){
    cout << check(10) << endl;
    cout << check(9) << endl;
    return 0;
}