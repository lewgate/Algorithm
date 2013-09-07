#include <iostream>
void InsertSort(int *pArray, int length){
    if(pArray == NULL || length <= 1)
        return;
    for(int j = 1; j < length; j++){
        int i = j - 1;
        int key = pArray[j];
        while(i >= 0 && pArray[i] > key){
            pArray[i+1] = pArray[i];
            i--;
        }
        pArray[i+1] = key;
    }
    return ;
}
int main(){
    int length;
    std::cin>>length;
    int *pArray = new int[length];
    for(int k = 0; k < length; k++)
        std::cin>>pArray[k];
    InsertSort(pArray, length);
    for(int k = 0; k < length; k++)
        std::cout<<pArray[k]<<'\t';
    delete [] pArray;
    return 0;
}

