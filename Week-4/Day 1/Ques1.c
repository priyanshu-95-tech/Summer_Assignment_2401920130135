int maxArea(int*h,int hSz){
    int a=0,b=hSz-1,m=0;
    while(a<b){
        int w=b-a;
        int l=(h[a]<h[b])?h[a]:h[b];
        int c=w*l;
        if(c>m){
            m=c;
        }
        if(h[a]<h[b]){
            a++;
        }else{
            b--;
        }
    }
    return m;
}