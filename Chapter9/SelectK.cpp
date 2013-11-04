#include <iostream>
using namespace std;
template <typename T>
void Swap(T *a, T *b){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}
template <typename T>
int Partition(T *pArray, int left, int right){
    T ref = pArray[right];
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
template <typename T>
T SelectK(T *pArray, int left, int right, int k){
    if(left == right && k == 1)
        return pArray[left];
    int mid = Partition(pArray, left, right);
    int i = mid -left + 1;
    if(i == k)
        return pArray[mid];
    else if(i < k)
        return SelectK(pArray, mid+1, right, k-mid-1);
    else
        return SelectK(pArray, left, mid-1, k);
    
} 
template <typename T>
void Print(T *pArray, int length){
    for(int i = 0; i < length; i++)
        cout<<pArray[i]<<" ";
    cout<<endl;
}
    
int main(){
    int array[] = {3, 1, 4, 2, 12,343, 12, 43};
    for(int i = 1; i<=8; i++)
        cout<<SelectK(array, 0, 7, i)<<endl;
    return 0;
}

