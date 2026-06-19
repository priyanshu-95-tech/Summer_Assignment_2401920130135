void sortColors(int*n,int nSz){
    int a=0,b=0,c=nSz-1;
    while(b<=c){
        if(n[b]==0){
            int t=n[a];
            n[a]=n[b];
            n[b]=t;
            a++;
            b++;
        }
        else if(n[b]==1){
            b++;
        }
        else{
            int t=n[b];
            n[b]=n[c];
            n[c]=t;
            c--;
        }
    }
}