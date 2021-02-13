#include<iostream>
#include<vector>
using namespace std;

int main(){
    // creating vector of a defined size
    vector<int> v(10);
    for(int i=0; i < v.size(); i++){
        cout << v[i] << endl;
    }

    // creating a vector without mentioning size. it will create an empty vector
    vector<int> v1;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << endl;
    }
    
    return 0;
}