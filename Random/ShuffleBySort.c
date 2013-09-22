#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct{
    int index;
    int key;
} Node;

int compare(const void *a, const void *b){
    return  ((Node*)a)->key - ((Node*)b)->key;
}

void ShuffleBySort(int *pArray, int length){
    Node *pNodeArray = (Node*)malloc(length*sizeof(Node));
    srand(time(NULL));
    for(int i = 0; i < length; i++){
        pNodeArray[i].index = i;
        pNodeArray[i].key = rand();
    }
    qsort(pNodeArray, length, sizeof(Node), compare);
    for(int i = 0; i < length; i++)
        pArray[i] = pNodeArray[i].index;
    free(pNodeArray);
}
int main(int argc, char * argv[]){
    if (argc != 2)
        return -1;
    int length = atoi(argv[1]);
    int *pArray = (int *)malloc(length*sizeof(int));
    ShuffleBySort(pArray, length);
    for(int i = 0; i < length; i++)
        printf("%d ", pArray[i]);
    printf("\n");
    free(pArray);
    return 0;
}
