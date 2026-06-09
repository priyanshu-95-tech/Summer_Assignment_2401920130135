int* grayCode(int n, int* returnSize) {
    int t=1<<n;
    *returnSize =t;
    int* a=(int*)malloc(t*sizeof(int));
    int b=0;
    while (b < t) {
        a[b]=b^ (b>>1);
        b++;
    }
    return a;
}