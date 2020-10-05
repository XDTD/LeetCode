#define max(a,b)  a>b?a:b
int isAll1(char** matrix, int step,int i,int j){
    int ii,jj;
    for(ii=i;ii<=i+step;ii++){
        for(jj=ii+j;jj<=j+step;jj++){
            if(matrix[ii][jj]=='0'||matrix[jj][ii]=='1') return 0;
        }
    }
    return 1;
}


int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int i,j,ans=0;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize;j++){
            if(matrix[i][j]=='1'){
                int step;
                for(step=1;step+i<matrixSize&&step+j<matrixColSize&&matrix[i+step][j+step]=='1';step++);
                if(isAll1(matrix,step,i,j)) ans=max(ans,(step+1)*(step+1));
            }
        }
    }
    return ans;
}

int main(){
    int matrix[4][5]={{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    printf("%d",maximalSquare(matrix,4,5));
}