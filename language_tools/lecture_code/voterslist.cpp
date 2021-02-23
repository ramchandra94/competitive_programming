#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> getVoters(int arr[], int total){
    sort(arr, arr+total);
    vector<int> result;
    for(int i=0; i < total; i++){
        int count =0;
        int j = i;
        while(j < total && arr[j] == arr[i]){
            j++;
            count++;
        }
        if(count >= 2){
            result.push_back(arr[i]);
        }
        i = j;
    }
    return result;
}

int main(){
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int total = n1 + n2 + n3;
    int arr[total];
    for(int i=0; i < total; i++){
        cin >> arr[i];
    }

    vector<int> voters = getVoters(arr, total);
    cout << voters.size();
    for(int i=0; i < voters.size(); i++){
        cout << voters[i] << endl;
    }
    return 0;
}