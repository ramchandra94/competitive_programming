#include<iostream>
#include<vector>
#include<unordered_set>
#include<stack>
using namespace std;

void dfs(vector<int>* edges, int start, unordered_set<int>& visited, stack<int>& finishedVertices){
    visited.insert(start);
    for(int i=0; i < edges[start].size(); i++){
        if(visited.count(edges[start][i]) == 0){
            dfs(edges, edges[start][i], visited, finishedVertices);
        }
    }
    finishedVertices.push(start);
    return;
}

void dfs2(vector<int>* edges, int start, unordered_set<int>* component, unordered_set<int>& visited){
     visited.insert(start);
     component->insert(start);
     for(int i=0; i < edges[start].size(); i++){
         if(visited.count(edges[start][i]) == 0){
             dfs2(edges, start, component, visited);
         }
     }
     return;
}
unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges, vector<int>* edgesT, int n){
    unordered_set<int> visited;
    stack<int> finishedVertices;
    for(int i=0; i < n; i++){
        if(visited.count(i) == 0){
            dfs(edges, i, visited, finishedVertices);
        }
    }
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    visited.clear();
    while(!finishedVertices.empty()){
        int element = finishedVertices.top();
        finishedVertices.pop();
        if(visited.count(element) != 0){
            continue;
        }
        unordered_set<int>* component = new unordered_set<int>();
        dfs2(edgesT, element, component, visited);
        output->insert(component);
    }
    return output;
}

int main(){
    int n;
    cin >> n;
    vector<int>* edges = new vector<int>[n];
    vector<int>* edgesT = new vector<int>[n];
    int m;
    cin >> m;
    for(int i=0; i < m; i++){
        int j, k;
        cin >> j >> k;
        edges[j-1].push_back(k-1);
        edgesT[k-1].push_back(j-1);
    }
    unordered_set<unordered_set<int>*>* components = getSCC(edges, edgesT, n);
    unordered_set<unordered_set<int>*>::iterator it;
    for(it = components->begin(); it != components->end(); it++){
        unordered_set<int>::iterator it1;
        unordered_set<int>* component = *it;
        for(it1 = component->begin(); it1 != component->end(); it1++){
            cout << *it1 << " ";
        }
        cout << endl;
        delete component;
    }
    delete components;
    delete[] edges;
    delete[] edgesT;
    return 0;
}