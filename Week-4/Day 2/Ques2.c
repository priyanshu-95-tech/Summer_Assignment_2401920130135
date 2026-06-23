int cmp(const void*a,const void*b){
    return(*(int**)a)[0]-(*(int**)b)[0];
}

int**merge(int**i,int iSz,int*iCol,int*rSz,int**rCol){
    qsort(i,iSz,sizeof(int*),cmp);
    int**r=(int**)malloc(iSz*sizeof(int*));
    *rCol=(int*)malloc(iSz*sizeof(int));
    int k=0;
    r[0]=i[0];
    (*rCol)[0]=iCol[0];
    for(int j=1;j<iSz;j++){
        if(i[j][0]<=r[k][1]){
            if(i[j][1]>r[k][1])r[k][1]=i[j][1];
        }else{
            k++;
            r[k]=i[j];
            (*rCol)[k]=iCol[j];
        }
    }
    *rSz=k+1;
    return r;
}