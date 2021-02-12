#include<bits/stdc++.h>
#include<climits>
using namespace std;

bool checkPossibility(int *numCandies, int numBoxes, int numStudents, int result){
    int studentsPossible = 0;
    for(int i=0; i < numBoxes; i++){
        if(numCandies[i] >= result){
            studentsPossible += (numCandies[i]/result);
        }
    }
    
    return studentsPossible >= numStudents ? true : false;
}

long long getMaxCandies(int *numCandies, int numBoxes, int numStudents){
    long long totalCandies = 0;
    long long maxCandies = INT_MIN;
    for(int i=0; i < numBoxes; i++){
        totalCandies += numCandies[i];
        if(numCandies[i] > maxCandies){
            maxCandies = numCandies[i];
        }
    }
    
    long long bestResult = 0;
    if(totalCandies == numStudents){
        return 1;
    }
    if(totalCandies < numStudents){
        return bestResult;
    }
    
    long long avgCandies = totalCandies/numStudents;
    long long start = 1;
    long long end = min(avgCandies, maxCandies);

    while(start <= end){
        long long tryThis = start + (end-start)/2;
        bool possibility = checkPossibility(numCandies, numBoxes, numStudents, tryThis);
        if(possibility){
			if(tryThis > bestResult){
                bestResult = tryThis;
            }
            start = tryThis + 1; 
    	}
        else{
            end = tryThis-1;
        }
        
    }
    return bestResult;
}

int main() {

	// Write your code here
    int t;
    cin >> t;
    while(t--){
        int numBoxes, numStudents;
        cin >> numBoxes >> numStudents;
        int *numCandies = new int[numBoxes];
        for(int i=0; i < numBoxes; i++){
            cin >> numCandies[i];
        }
        cout << getMaxCandies(numCandies, numBoxes, numStudents) << endl;
    }
}