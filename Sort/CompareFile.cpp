#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int main(int argc, char * argv[]){
    if(argc != 3)
        return -1;
    FILE *pFid1 = fopen(argv[1], "r");
    FILE *pFid2 = fopen(argv[2], "r");
    if(pFid1 == NULL || pFid2 == NULL)
        return -1;
    int length1, length2;  
    fscanf(pFid1, "%d", &length1);
    fscanf(pFid2, "%d", &length2);
    if(length1 != length2){
        std::cout<<"not equal\n";
        return -1;
    }
    int *pArray1 = new int[length1];
    int *pArray2 = new int[length2];
    for(int k = 0; k < length1; k++){
        fscanf(pFid1, "%d", &pArray1[k]);
        fscanf(pFid2, "%d", &pArray2[k]);
        if(pArray1[k] != pArray2[k]){
            std::cout<<"not equal\n";
            return -1;
        }
    }
    delete [] pArray1;
    delete [] pArray2;
    fclose(pFid1);
    fclose(pFid2);
    std::cout<<"equal\n";
    return 0;
}
