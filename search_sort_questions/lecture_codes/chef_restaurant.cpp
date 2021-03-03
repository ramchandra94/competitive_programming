// codechef problem https://www.codechef.com/problems/CHEFRES

#include<iostream>
#include<algorithm>
using namespace std;

bool comparator(const pair<int, int> p1, const pair<int, int> p2){
    return p1.first < p2.first;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        pair<int, int> *pairArr = new pair<int, int>[n];
        for(int i=0; i < n; i++){
            cin >> pairArr[i].first;
            cin >> pairArr[i].second;
        }
        sort(pairArr, pairArr+n, comparator);
        int *visited = new int[m];
        for(int i=0; i < m; i++){
            cin >> visited[i];
        }
        cout << "result is " << endl;
        for(int i=0; i < m; i++){
            int curr =  visited[i];
            int start = 0, end = n-1;
            int mid = (start + end)/2;
            int min = n; bool printed = false;
            while(start <= end){
                if(pairArr[mid].first == curr){
                    cout << 0 << endl;
                    printed = true;
                    break;
                } 
                else if(pairArr[mid].first < curr){
                    if(pairArr[mid].second > curr){
                        cout << 0 << endl;
                        printed = true;
                        break;
                    }
                    else {
                        start = mid + 1;
                    }
                }
                else {
                    min = mid;
                    end = mid - 1;
                }
                mid = (start+end)/2;
            }
            if(!printed){
                if(min == n){
                    cout << -1 << endl;
                }else{
                    cout << pairArr[min].first - curr << endl;
                }
            }
        }

    }
    return 0;
}