int maxProfit(int* prices,int pricesSize){
    int max_prof=0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i]>prices[i-1]){
            max_prof+=prices[i]-prices[i-1];
        }
    }
    return max_prof;
}