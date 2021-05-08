#include <iostream>
#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;

#define mod 1000000007

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    if(a >= b){
        return gcd(b, a%b);
    }
    if(b > a){
        return gcd(a, b%a);
    }
}
void printMap(unordered_map<int, int> map){
    cout << "##################" << endl;
    for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
        cout << "key: " << (*it).first << " value: " << (*it).second << endl;
    }
    cout << "##################" << endl;
}

int main()
{
    int n;
    cin >> n;
    
    int *input = new int[n];
    for(int i=0; i < n; i++){
        cin >> input[i];
    }
        
    // maintain the gcd map till ith index
    vector<unordered_map<int, int> > gcdMaps;
    long long final_result = 0;
    
    for(int i=0; i < n; i++){
        unordered_map<int, int> newContribs;
        
        for(int j=i-1; j >= 0; j--){
            if(input[j] < input[i])
            {
                // iterate over all elements at gcdMaps[prev_index] and create your contrib map
                // your contribMap final will be gcdMaps[prev_index] merged with your contrib map.
                // add up to the global count after this step.
                unordered_map<int, int> prevContribs = gcdMaps[j];
                unordered_map<int, int>::iterator it;

                for(it = prevContribs.begin(); it != prevContribs.end(); it++){
                    if((*it).first <= input[i]){
                        int gcd_now = gcd(input[i], (*it).first);
                        if(newContribs.count(gcd_now) > 0){
                            newContribs.at(gcd_now) = (newContribs.at(gcd_now) + (*it).second) % mod;
                        }else{
                            newContribs.insert(make_pair(gcd_now, (*it).second));
                        }
                    }
                }
        	}
        }
        
        if(newContribs.count(input[i]) > 0)
        {
            newContribs.at(input[i]) = (newContribs.at(input[i]) + 1) % mod;
        }
        else
        {
            newContribs.insert(make_pair(input[i], 1));
        }
        gcdMaps.push_back(newContribs);
        if(newContribs.count(1) > 0){
            final_result = (final_result + newContribs.at(1)) % mod;
        }
    }
    cout << final_result << endl;
    
    return 0;

}
