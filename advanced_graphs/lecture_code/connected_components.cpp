#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void DFS(vector<int>* edges, int start, unordered_set<int>* component, bool* visited){
    visited[start] = true;
    component->insert(start);
    vector<int>::iterator it;
    for(it = edges[start].begin(); it != edges[start].end(); it++){
        if(!visited[*it]){
            DFS(edges, *it, component, visited);
        }
    }

    return;
}
unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n){
    bool *visited = new bool[n];
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for(int i=0; i < n; i++){
        visited[i] = false;
    }

    for(int i=0; i < n; i++){
        if(!visited[i]){
            unordered_set<int>* component = new unordered_set<int>();
            DFS(edges, i, component, visited);
            output->insert(component);
        }
    }
    delete[] visited;
    return output;
}

int main(){
    int n;
    cin >> n;

    // lets create a vector array to store the edges from all the vertices to its connected vertices

    vector<int>* edges = new vector<int>[n];

    int m;
    cin >> m;

    for(int i=0; i < m; i++){
        int j, k;
        cin >> j >> k;
        edges[j-1].push_back(k-1);
        edges[k-1].push_back(j-1);
    }

    unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
    unordered_set<unordered_set<int>*>::iterator it = components->begin();
    while (it != components->end())
    {
        unordered_set<int>* curr = *it;
        for(unordered_set<int>::iterator it1 = curr->begin(); it1 != curr->end(); it1++){
            cout << (*it1) + 1 << " ";
        }
        cout << endl;
        delete curr;
        it++;
    }
    delete components;
    delete[] edges;
    return 0;
    
}