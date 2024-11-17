#include <stdio.h> 
#include <stdbool.h> 

void main(){
    int k = 0;
    int bal = 1000;
    int trnsctn[] = {200, -500, -400, 100 , -100, 300, 500};
    int length = sizeof(trnsctn) / sizeof(trnsctn[0]);
    int tobeprocessed[10];
    for (int i = 0; i < length; i++){
        if (trnsctn[i] >= 0)
        bal = bal + trnsctn[i];
    if (trnsctn[i] < 0){
        printf("Transaction of %d skipped.\n", trnsctn[i]);
        if (bal < (trnsctn[i]*(-1))){
            printf("wrong transaction\n");
            tobeprocessed[k] = trnsctn[i];
            k++;
        }
        else {
        bal = bal + trnsctn[i];
        }
        if (bal == 0){
            for (int m = i; m <= length; m++){
            tobeprocessed[k] =  trnsctn[m+1];
            k++;
            }
            k = k - 2;
            printf("no further transactions can be processed\n");
            break;
        }
        

    }
}
printf("final amt= %d\n", bal);
    for (int j=0; j<k; j++){
        printf("%d\n",tobeprocessed[j]);
}
}