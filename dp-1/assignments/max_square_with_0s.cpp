// similar problems of leetcode
// https://leetcode.com/problems/maximal-rectangle/
// https://leetcode.com/problems/maximal-square/

using namespace std;
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
    if(n == 0 || m == 0){
        return 0;
    }
    int result = 0;
    pair<int,int> **out = new pair<int, int>*[n];
    for(int i=0; i < n; i++){
        out[i] = new pair<int, int>[m];
    }
    
    for(int i=0; i < n; i++){
        if(arr[i][0] == 0){
            out[i][0] = make_pair(1, 1);
            result = 1;
        }else{
            out[i][0] = make_pair(0, 0);
        }
    }
    
    for(int i=1; i < m; i++){
        if(arr[0][i] == 0){
            out[0][i] = make_pair(1, 1);
            result = 1;
        }else{
            out[0][i] = make_pair(0, 0);
        }   
    }
    
    for(int i=1; i < n; i++){
        for(int j=1; j < m; j++){
            if(arr[i][j] == 1){
                out[i][j] = make_pair(0, 0);
            }
            else{
                int first = min(min(out[i-1][j-1].first, out[i-1][j].first), out[i][j-1].first) + 1;
                int second = min(min(out[i-1][j-1].second, out[i-1][j].second), out[i][j-1].second) + 1;
                out[i][j] = make_pair(first, second);
                int temp = min(first, second);
                if(temp > result){
                    result = temp;
                }
            }
        }
    }
    return result;
}