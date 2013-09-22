#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void ShuffleByExchange(int *pArray, int length){
    srand(time(NULL));
    for(int i = 0; i < length; i++)
        pArray[i] = i;
    for(int i = 0; i < length; i++){
        int index = rand()%(length-i) + i;
        if(i != index)
            swap(pArray+i, pArray+index);
    }
}
int main(int argc, char * argv[]){
    if(argc != 2)
        return -1;
    int length = atoi(argv[1]);
    int *pArray = (int *)malloc(length*sizeof(int));
    ShuffleByExchange(pArray, length);
    for(int i = 0; i < length; i++)
        printf("%d ", pArray[i]);
    printf("\n");
    free(pArray);
    return 0;
}





        
