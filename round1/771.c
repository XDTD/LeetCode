int numJewelsInStones(char* J, char* S) {
    int i=0,j=0,res=0;
    while(S[i]!='\0'){
        j=0;
        while(J[j]!='\0'){
            if(J[j]==S[i]){
                res++;
                break;
            }
            j++;
        }
        i++;
    }
    return res;
}
