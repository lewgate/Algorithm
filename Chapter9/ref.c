#include <stdio.h>
#include <stdlib.h>

static int comp(const void *p1, const void *p2){
    return *((int*)p1) - *((int*)p2);
}
int main(int argc, char * argv[]){
    if(argc != 3){
        fprintf(stderr, "input parameters error\n");
        return -1;
    }
    FILE *pfid1 = fopen(argv[1], "r");
    FILE *pfid2 = fopen(argv[2], "r");
    int length1, length2;
    fscanf(pfid1, "%d", &length1);
    fscanf(pfid2, "%d", &length2);
    int *pArray = (int *)malloc(sizeof(int)*(length1+length2));
    int index = 0;
    for(int i = 0; i < length1; i++){
        fscanf(pfid1, "%d", pArray+index);
        index++;
    }
    for(int i = 0; i < length2; i++){
        fscanf(pfid2, "%d", pArray+index);
        index++;
    }
    qsort(pArray, length1+length2, sizeof(int), comp);
    printf("Median: %d\n", pArray[(length1+length2)/2-1]);
    free(pArray);
    fclose(pfid1);
    fclose(pfid2);
}

