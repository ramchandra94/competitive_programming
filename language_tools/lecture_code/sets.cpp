#include<iostream>
// this is to access pair and it's utility methods
#include<utility>
#include<set>
using namespace std;

int main(){
    set<int> s;
    int arr[] = {1, 2, 3, 4 ,5, 6, 5};
    for(int i=0; i < 7; i ++){
        s.insert(arr[i]);
    }
    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        cout << *it << endl;
    }
    // s.find finds and return an iterator to the element
    if(s.find(7) == s.end()){
        cout << "element not found" << endl;
    }else{
        cout << "element found" << endl;
    }
    return 0;
}