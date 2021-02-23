#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;


class Student{
    public:
    string name;
    int marks;
    int roll_num;
    
    Student(){
        
    }
    Student(string name, int marks, int roll_num){
        this->name = name;
        this->marks = marks;
        this->roll_num = roll_num;
    }
    
    bool operator<(const Student& s){
        if(marks > s.marks){
             return true;
        }
        if(marks == s.marks){
            if(roll_num < s.roll_num){
                return true;
            }
         }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    Student studs[n];
    for(int i=0; i < n; i++){
        string temp_name;
        getchar();
        getchar();
        getline(cin, temp_name, ' ');
        int subj1, subj2, subj3;
        cin >> subj1 >> subj2 >> subj3;
        studs[i] = Student(temp_name, subj1+subj2+subj3, i+1);
    }
    sort(studs, studs+n);
    for(int i=0; i < n; i++){
        cout << i+1 << " " << studs[i].name << endl;
    }
	return 0;
}
