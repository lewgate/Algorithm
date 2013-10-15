#include <stdio.h>
#include <stdlib.h>
void Swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int *pArray, int left, int right){
    int ref = pArray[right];
    int i = left - 1;
    for(int j = left; j <= right-1; j++){
        if(pArray[j] < ref){
            i++;
            if(i != j)
                Swap(pArray+i, pArray+j);
        }
    }
    Swap(pArray+i+1, pArray+right);
    return i+1;
}
void QuickSort(int *pArray, int left, int right){
    if(left < right){
        int q = Partition(pArray, left, right);
        QuickSort(pArray, left, q-1);
        QuickSort(pArray, q+1, right);
    }
}

int main(){
    int length;
    scanf("%d", &length);
    int *pArray = (int *)malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
        scanf("%d", pArray+i);
    QuickSort(pArray, 0, length-1);
    printf("%d\n", length);
    for(int i = 0; i < length; i++)
        printf("%d\t", pArray[i]);
    free(pArray);
    return 0;
}
