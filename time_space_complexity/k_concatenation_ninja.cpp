#include<iostream>
#include<climits>

using namespace std;

typedef long long ll;

ll kadane(int arr[], int n){
    ll curr_sum = 0;
    ll best_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
        if (best_sum < curr_sum)
        {
            best_sum = curr_sum;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return best_sum;
}
ll solution(int arr[], int n, int k){
    ll kadane_sum = kadane(arr, n);
    if(k == 1){
        return kadane_sum;
    }
    ll curr_prefix_sum = 0; ll curr_suffix_sum = 0;
    ll max_prefix_sum = INT_MIN, max_suffix_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curr_prefix_sum = curr_prefix_sum + arr[i];
        max_prefix_sum = max(curr_prefix_sum, max_prefix_sum);
    }
    ll total_sum = curr_prefix_sum;
    for(int i=n-1; i >= 0; i++){
        curr_suffix_sum = curr_suffix_sum + arr[i];
        max_suffix_sum = max(curr_suffix_sum, max_suffix_sum);
    }

    ll ans;
    if(total_sum < 0){
        ans =  max(max_prefix_sum + max_suffix_sum, kadane_sum);
    }
    else{
        ans = max(max_suffix_sum+(k-2)*total_sum+max_prefix_sum, kadane_sum);
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        cout << solution(arr, n, k) << endl;
    }
    
    return 0;
}