#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool findPossibility(long int *arr, long int start, long int end, long int d, int count){
    int i = start;
    while(count > 1){
        int j = i + 1;
        while(j <= end && arr[j]-arr[i] < d){
            j++;
        }
        if(j > end){
            return false;
        }
        i = j;
        count--;
    }
    return true;
}

int main() {

	// Write your code here
    int t;
    cin >> t;
    while(t--){
        int numStalls, numCows;
        cin >> numStalls >> numCows;
        long int *stallPos = new long int[numStalls];
        for(int i=0; i < numStalls; i++){
            cin >> stallPos[i];
        }
        sort(stallPos, stallPos+numStalls);
        long int start = 0;
        long int end = stallPos[numStalls-1]-stallPos[start];
        int best_distance = 0;
        while(start <= end){
            long int mid = start + (end-start)/2;
            bool val = findPossibility(stallPos, 0, numStalls-1, mid, numCows);
            if(val){
                if(mid > best_distance){
                    best_distance = mid;
                }
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        cout << best_distance << endl;
        
    }
    return 0;
}