char*intToRoman(int a){
    int v[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char*s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    char*r=(char*)malloc(20*sizeof(char));
    r[0]='\0';
    for(int i=0;i<13;i++){
        while(a>=v[i]){
            strcat(r,s[i]);
            a-=v[i];
        }
    }
    return r;
}