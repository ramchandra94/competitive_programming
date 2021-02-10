#include<unordered_map>

string uniqueChar(string str) {
	// Write your code here
    unordered_map<char, bool> map;
    
    string output;
    
    for(int i=0; i < str.length(); i++){
        if(map.count(str[i]) == 0){
            output.push_back(str[i]);
            map.insert({str[i], true});
        }
    }
    
    return output;
}