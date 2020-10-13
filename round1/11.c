#define abs(x) x>0?x:(-x)
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

/**
*   参考了官方题解
*/
int maxArea(int* height, int heightSize) {
    if(heightSize==0||heightSize==1)
        return 0;
    int res,i=0,j=heightSize-1,minheight=min(height[i],height[j]);
    res=(j-i)*minheight;
    while(i<j){
        minheight=min(height[i],height[j]);
        res=max(res,(j-i)*minheight);
        if(height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return res;

}
