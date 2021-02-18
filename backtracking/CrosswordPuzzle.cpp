#include<bits/stdc++.h>
using namespace std;

#define N 10

bool isPossibleHorizontal(char **grid, string word, int i, int j){
    for(int k=0; k < word.size(); k++){
        if(j+k >= 10 || (grid[i][j+k] != '-' && grid[i][j+k] != word[k])){
            return false;
        }
    }
    return true;
}

bool isPossibleVertical(char **grid, string word, int i, int j){
    for(int k=0; k < word.size(); k++){
        if(i+k >= 10 || grid[i+k][j] != '-' && grid[i+k][j] != word[k]){
            return false;
        }
    }
    return true;
}

vector<bool> insertHorizontal(char **grid, string word, int i, int j){
    vector<bool> posBool;
    for(int k=0; k < word.size(); k++){
        if(grid[i][j+k] == word[k]){
            posBool.push_back(false);
        }else{
            grid[i][j+k] = word[k];
            posBool.push_back(true);
        }
    }
    return posBool;
}
vector<bool> insertVertical(char **grid, string word, int i, int j){
    vector<bool> posBool;
    for(int k=0; k < word.size(); k++){
        if(grid[i+k][j] == word[k]){
            posBool.push_back(false);
        }else{
            grid[i+k][j] = word[k];
            posBool.push_back(true);
        }
    }
    return posBool;
}
void resetHorizontal(char **grid, vector<bool> posBool, int i, int j){
    for(int k=0; k < posBool.size(); k++){
        if(posBool[k]){
            grid[i][j+k] = '-';
        }
    }
}

void resetVertical(char **grid, vector<bool> posBool, int i, int j){
    for(int k=0; k < posBool.size(); k++){
        if(posBool[k]){
            grid[i+k][j] = '-';
        }
    }
}
bool fillGridHelper(char **grid, vector<string> words, int numWords, int currIndex){
    if(currIndex == numWords){
        return true;
    }
    string currWord = words[currIndex];
    for(int i=0; i < 10; i++){
        for(int j=0; j < 10; j++){
            if(isPossibleHorizontal(grid, currWord, i, j)){
                vector<bool> posBool = insertHorizontal(grid, currWord, i, j);
                bool nextWordPossibility = fillGridHelper(grid, words, numWords, currIndex+1);
                if(nextWordPossibility){
                    return true;
                }
                resetHorizontal(grid, posBool, i, j);
            }
            if(isPossibleVertical(grid, currWord, i, j)){
                vector<bool> posBool = insertVertical(grid, currWord, i, j);
                bool nextWordPossibility = fillGridHelper(grid, words, numWords, currIndex+1);
                if(nextWordPossibility){
                    return true;
                }
                resetVertical(grid, posBool, i, j);
            }
        }
    }
    return false;
}
void fillGrid(char **grid, vector<string> words, int numWords, int currIndex){
    fillGridHelper(grid, words, numWords, currIndex);
    
    for(int i=0; i < 10; i++){
        for(int j=0; j < 10; j++){
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main() {

	// Write your code here
    char **grid = new char*[10];
    for(int i=0; i < 10; i++){
        grid[i] = new char[10];
        for(int j=0; j < 10; j++){
            cin >> grid[i][j];
        }
    }
    getchar();
    vector<string> words;
    string temp;
    while(getline(cin, temp, ';')){
    	words.push_back(temp);
    }

    fillGrid(grid, words, words.size(), 0);
    return 0;
}