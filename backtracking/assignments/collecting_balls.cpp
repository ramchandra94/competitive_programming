#include<bits/stdc++.h>
using namespace std;
bool sharmaWinsK(long long n, long long k){
    long long total = n;
    long long sharma = 0;
    long long singh = 0;
    while(n > k){
        long long sharmaShare = k;
        sharma += sharmaShare;
        n = n - sharmaShare;
        long long singhShare = n/10;
        n = n - singhShare;
        singh += singhShare;
    }
    
    sharma += n; 
    if(sharma >= total/2 && sharma >= singh){
        return true;
    }
    else{
        return false;
    }
}
long long sharmaWins(long long start, long long end, long long n){
    long long minimum = n;
    while(start <= end){
        long long mid = start + (end - start)/2;
        bool checkMid = sharmaWinsK(n, mid);
        if(checkMid){
			if(mid < minimum){
                minimum = mid;
            }
            end = mid -1;
        } else{
            start = mid + 1;
        }
    }
	return minimum;
}

int main()
{
    long long n;
    cin >> n;
    cout << sharmaWins(1, n, n) << endl;
	return 0;
}
