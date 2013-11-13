#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int compare(const void *a , const void *b){
    return(*(int*) a-*(int*) b);
}
int main(int argc, char *argv[]){
    if(argc != 2)
        return -1;
    int length = atoi(argv[1]);
    FILE *pFid = fopen("TestData.txt", "w");
    if(pFid == NULL)
        return -1;
    fprintf(pFid, "%d\n", length);
    int *pArray = new int[length];
    srand(time(NULL));
    for(int k = 0; k < length; k++){
        pArray[k] = rand();
        fprintf(pFid, "%d\t", pArray[k]);
    }
    fclose(pFid);
    FILE *pFidResult = fopen("ResultData.txt", "w");
    if(pFidResult == NULL)
        return -1;
    fprintf(pFidResult, "%d\t", length);
    qsort(pArray, length, sizeof(int), compare);
    for(int k = 0; k < length; k++)
        fprintf(pFidResult, "%d\t", pArray[k]);
    delete [] pArray;
    fclose(pFidResult);
    return 0;
}



