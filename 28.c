int* get_next(char* needle){
    int lenOfneedle=strlen(needle);
    int* next=(int *) malloc(sizeof(int)*lenOfneedle);
    next[0] = -1;
    int j = 0;
    int k = -1;
    while(j<lenOfneedle - 1){
        if(k == -1 || needle[k] == needle[j]){
            j++;
            k++;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
    return next;
}


int strStr(char* haystack, char* needle){
    int lenOfhaystack=strlen(haystack),lenOfneedle=strlen(needle);
    if(lenOfneedle==0)
        return 0;
    int* next = get_next(needle);
    int i=0;
    int j=0;
    while(i < lenOfhaystack && (j <lenOfneedle)){
        if(j == -1 || haystack[i] == needle[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }

    }
    if(j == lenOfneedle){
        return i-j;
    }else{
        return -1;
    }
}