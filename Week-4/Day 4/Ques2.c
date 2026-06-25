int jump(int*n,int nSz){
    if(nSz<=1)return 0;
    int j=0,e=0,f=0;
    for(int i=0;i<nSz-1;i++){
        if(i+n[i]>f)f=i+n[i];
        if(i==e){
            j++;
            e=f;
            if(e>=nSz-1)break;
        }
    }
    return j;
}