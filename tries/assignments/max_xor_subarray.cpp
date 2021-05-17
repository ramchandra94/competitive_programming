#include<iostream>
#include<cmath>
using namespace std;

class TrieNode{
    public:
    TrieNode *left;
    TrieNode *right;
};

void insert(int n, TrieNode *head){
    TrieNode *curr = head;
    
    for(int i=31; i >= 0; i--){
        int bit = (n >> i)&1;
        if(bit == 1){
            if(!curr->right){
                curr->right = new TrieNode();
            }
            curr = curr->right;
        } else {
            if(!curr->left){
                curr->left = new TrieNode();
            }
            curr = curr->left;
        }
    }
    return;
}

int findMaxXorInTrie(int n, TrieNode *head) {
    TrieNode *curr = head;
    int max_val = 0;
    for(int i=31; i >= 0; i--){
        int bit = (n >> i)&1;
        if(bit == 1){
            if(curr->left){
                max_val += pow(2, i);
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }else{
            if(curr->right){
                max_val += pow(2, i);
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
    }
    return max_val;
}

int findMaxXorSubArray(int *arr, int n){
    TrieNode *head = new TrieNode();
    int prev_xor = arr[0];
    int max_xor = arr[0];
    insert(arr[0], head);
    for(int i=1; i < n; i++){
        int curr_xor = prev_xor ^ arr[i];
        insert(curr_xor, head);
        int max_trie_val = findMaxXorInTrie(curr_xor, head);
        int curr_max = max(curr_xor, max_trie_val);
        if(curr_max > max_xor){
            max_xor = curr_max;
        } 
        prev_xor = curr_xor;
    }
    return max_xor;
}

int main() {

	// Write your code here
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << findMaxXorSubArray(arr, n) << endl;
}