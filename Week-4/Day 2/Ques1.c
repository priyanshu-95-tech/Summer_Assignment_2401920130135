char*addBinary(char*a,char*b){
    int n=strlen(a),m=strlen(b);
    int l=(n>m?n:m)+2;
    char*r=(char*)malloc(l*sizeof(char));
    r[l-1]='\0';
    int i=n-1,j=m-1,k=l-2,c=0;
    while(i>=0||j>=0||c){
        int s=c;
        if(i>=0)s+=a[i--]-'0';
        if(j>=0)s+=b[j--]-'0';
        r[k--]=(s%2)+'0';
        c=s/2;
    }
    return r+k+1;
}