void heapify(int*a,int n,int i){
    int l=2*i+1;
    int r=2*i+2;
    int s=i;
    if(l<n&&a[l]<a[s])s=l;
    if(r<n&&a[r]<a[s])s=r;
    if(s!=i){
        int t=a[i];
        a[i]=a[s];
        a[s]=t;
        heapify(a,n,s);
    }
}
int findKthLargest(int*a,int n,int k){
    int*h=(int*)malloc(k*sizeof(int));
    for(int i=0;i<k;i++)h[i]=a[i];
    for(int i=k/2-1;i>=0;i--)heapify(h,k,i);
    for(int i=k;i<n;i++){
        if(a[i]>h[0]){
            h[0]=a[i];
            heapify(h,k,0);
        }
    }
    int r=h[0];
    free(h);
    return r;
}