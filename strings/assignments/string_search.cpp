// S and T - input strings
// You need to check if string T is present in S or not

int getLength(char ch[]) {
    int l = 0, i = 0;
    while(ch[i] != '\0'){
        i++;
        l++;
    }
    return l;
}
int* getLPS(char T[]) {
    int len = getLength(T);
    int *lps = new int[len];
    
    lps[0] = 0;
    int i = 1, j = 0;
    
    while(i < len){
        if(T[i] == T[j]){
            lps[i] = j + 1;
            i++; j++;
        }else{
            if(j != 0){
                j = lps[j-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
    
}

int kmp(char S[], char T[]) {
    int *lps = getLPS(T);
    int i = 0, j = 0;
    int textLen = getLength(S);
    int pattLen = getLength(T);
    while(i < textLen && j < pattLen) {
        if(S[i] == T[j]){
            i++; j++;
        } else {
            if(j != 0) {
                j = lps[j-1];
            } else{
                i++;
            }
        }
    }
    
    if(j == pattLen){
        return i - pattLen;
    }
    
    return -1;
}
int findString(char S[], char T[]) {
    // Write your code here
	return kmp(S, T);
}
