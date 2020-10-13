bool isAnagram(char* s, char* t) {
    int i=0;
    int s_num[26]={0},t_num[26]={0};
    for(i=0;s[i]!='\0';i++){
        s_num[s[i] - 'a']++;
    }
    for(i=0;t[i]!='\0';i++){
        t_num[t[i]-'a']++;
    }
    for(i=0;i<26;i++){
        if(s_num[i]!=t_num[i])
            return false;
    }
    return true;
}
