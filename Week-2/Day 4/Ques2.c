int majorityElement(int*nums,int n){
    int c=0;
    int a=0;
    for(int i=0;i<n;i++){
        if(c==0){
            a=nums[i];
        }
        if(nums[i]==a){
            c++;
        }else{
            c--;
        }
    }
    return a;
}