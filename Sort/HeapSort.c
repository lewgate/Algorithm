#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void HeapHeapify(int *pArray, int length, int index){
    if(pArray == NULL || index >= length)
        return;
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < length && pArray[left]>pArray[largest])
        largest = left;
    if(right < length && pArray[right]>pArray[largest])
        largest = right;
    if(index != largest){
        Swap(pArray+index, pArray+largest);
        HeapHeapify(pArray, length, largest);
    }
    return ;
}

void HeapHeapifyWhile(int *pArray, int length, int index){
    if(pArray == NULL || index >= length)
        return;
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < length && pArray[left]>pArray[largest])
        largest = left;
    if(right < length && pArray[right]>pArray[largest])
        largest = right;
    while(largest != index){
        Swap(pArray+index, pArray+largest);
        index = largest;
        left = 2*index + 1;
        right = 2*index + 2;
        if(left < length && pArray[left]>pArray[largest])
            largest = left;
        if(right < length && pArray[right]>pArray[largest])
            largest = right;
    }
}
void Build_Heap(int *pArray, int length){
    for(int i = length-1; i >= 0; i--)
        HeapHeapifyWhile(pArray, length, i);
}
void Heap_Sort(int *pArray, int length){
    Build_Heap(pArray, length);
    for(int i = length-1; i >= 1; i--){
        Swap(pArray+i, pArray);
        HeapHeapifyWhile(pArray, i, 0);
    }
}
            
int main(){
    int length;
    scanf("%d", &length);
    int *pArray = (int *)malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
        scanf("%d", pArray+i);
    Heap_Sort(pArray, length);
    printf("%d\n", length);
    for(int i = 0; i < length; i++)
        printf("%d\t", pArray[i]);
    free(pArray);
    return 0;
}
