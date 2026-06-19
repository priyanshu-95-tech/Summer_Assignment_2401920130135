int*twoSum(int*n,int nSz,int t,int*rSz){
    *rSz=2;
    int*r=(int*)malloc(2*sizeof(int));
    for(int i=0;i<nSz;i++){
        for(int j=i+1;j<nSz;j++){
            if(n[i]+n[j]==t){
                r[0]=i;
                r[1]=j;
                return r;
            }
        }
    }
    return r;
}