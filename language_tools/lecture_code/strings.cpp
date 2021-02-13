#include<iostream>
#include<string>
using namespace std;

int main(){
    string s = "ramchandra";

    // deep copy constructor
    string s1(s);

    // substring
    // this will create a string of length 100 from index 2. if the given length is more than 
    // the number of characters that can be possible to get from s, it will get only till the
    // end character of s.
    string s2(s, 2, 100);
    cout << s2 << endl;
    cout << s << endl;
    cout << s1 << endl;
    return 0;
}