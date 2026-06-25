void rotate(int**m,int mSz,int*mCol){
    for(int i=0;i<mSz;i++){
        for(int j=i+1;j<mSz;j++){
            int t=m[i][j];
            m[i][j]=m[j][i];
            m[j][i]=t;
        }
    }
    for(int i=0;i<mSz;i++){
        for(int j=0;j<mSz/2;j++){
            int t=m[i][j];
            m[i][j]=m[i][mSz-1-j];
            m[i][mSz-1-j]=t;
        }
    }
}