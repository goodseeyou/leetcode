int minPartitions(char* n){
    int max=0;
    for(int i=0;n[i] != NULL && n[i]!='\0';i++){
        int t = (int)(n[i]-'0');
        if(t > max){
            max=t;
        }
    }
    return max;
}
