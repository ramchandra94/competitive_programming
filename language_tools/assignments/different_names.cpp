#include <iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
    // Write your code here
    unordered_map<string, int> map;
    string str;
    bool flag = false;
    while(getline(cin, str, ' ')){
        if(map.count(str) == 0){
            map.insert({str, 1});
        }
        else{
            map[str]++;
            flag = true;
        }
    }
    
    if(flag){
        for(unordered_map<string, int>::iterator it = map.begin(); it != map.end(); it++){
        	if(it->second > 1){
            	cout << it->first << " " << it->second << endl;
        	}
    	}
    }
    else{
        cout << -1 << endl;
    }
    
    return 0;
    
}