int lengthOfLastWord(char * s) {
    int i = 0;
    while (s[i] !='\0') i++;
    int count = 0;
    int state = 0;
    while (--i>= 0){
        switch (state){
            case 0:
                if (s[i] != ' ') {
                    state = 1;
                    count++;
                }
                break;
            case 1:
                if(s[i] !=' '){
                    count++;
                }else{
                    return count;
                }
                break;
        }
        }
    return count;
}