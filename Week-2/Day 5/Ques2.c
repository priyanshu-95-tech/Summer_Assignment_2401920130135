int missingNumber(int*a,int n){
    int s=n*(n+1)/2;
    int c=0;
    for(int i=0;i<n;i++){
        c+=a[i];
    }
    return s-c;
}