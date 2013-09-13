#include<iostream>
#include<stdlib.h>
void SelectSort(int *pArray, int length){
    if(pArray == NULL || length <= 1)
        return;
    for(int pos = 0; pos < length; pos++){
        int min = pArray[pos];
        int minpos = pos;
       for(int k = pos; k < length; k++){
          if(min > pArray[k]){
              minpos = k;
              min = pArray[k];
          }
       }
       int tmp = pArray[pos];
       pArray[pos] = min;
       pArray[minpos] = tmp;
    }
    return;
}
int main(){
    int length;
    std::cin>>length;
    int *pArray = new int[length];
    for(int k = 0; k < length; k++)
        std::cin>>pArray[k];
    SelectSort(pArray, length);
    std::cout<<length<<std::endl;
    for(int k = 0; k < length; k++)
        std::cout<<pArray[k]<<'\t';
    return 0;
}



