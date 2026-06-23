int**insert(int**i,int iSz,int*iCol,int*nI,int nISz,int*rSz,int**rCol){
    int**r=(int**)malloc((iSz+1)*sizeof(int*));
    *rCol=(int*)malloc((iSz+1)*sizeof(int));
    int k=0,j=0;
    while(j<iSz&&i[j][1]<nI[0]){
        r[k]=i[j];
        (*rCol)[k]=iCol[j];
        k++;j++;
    }
    int*m=(int*)malloc(2*sizeof(int));
    m[0]=nI[0];m[1]=nI[1];
    while(j<iSz&&i[j][0]<=m[1]){
        if(i[j][0]<m[0])m[0]=i[j][0];
        if(i[j][1]>m[1])m[1]=i[j][1];
        j++;
    }
    r[k]=m;(*rCol)[k]=2;k++;
    while(j<iSz){
        r[k]=i[j];
        (*rCol)[k]=iCol[j];
        k++;j++;
    }
    *rSz=k;
    return r;
}