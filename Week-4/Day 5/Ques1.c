int uniquePaths(int m,int n){
    long long r=1;
    for(int i=1;i<n;i++){
        r=r*(m+i-1)/i;
    }
    return(int)r;
}