int hammingWeight(uint32_t n) {
    int c = 0;
    while ( n > 1 ) {
        if( n%2 == 1 ){
            c++;
        }
        n >>=1;
    }
    if(n==1){
        return c+1;
    }else{
        return c;
    }
}
