#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    int a_count = 0;
    int s_count = 0;
    int p_count = 0;
    for(int i=0; i < n; i++){
        int temp = getchar();
        char c_temp = (char)temp;
        if(c_temp == 'a'){
            a_count++;
        }
        if(c_temp == 's'){
            s_count++;
        }
        if(c_temp == 'p'){
            p_count++;
        }
    }
    cout << a_count << " " << s_count << " " << p_count << endl;
	return 0;
}
