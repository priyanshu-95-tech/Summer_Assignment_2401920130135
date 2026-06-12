int minPathSum(int**a,int n,int*c){
    int m=n;
    int k=*c;
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            if(i==0&&j>0)a[i][j]+=a[i][j-1];
            else if(j==0&&i>0)a[i][j]+=a[i-1][j];
            else if(i>0&&j>0)a[i][j]+=a[i-1][j]<a[i][j-1]?a[i-1][j]:a[i][j-1];
        }
    }
    return a[m-1][k-1];
}