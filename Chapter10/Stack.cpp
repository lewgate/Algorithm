#include <stdlib.h>
#include <iostream>
using namespace std;
template <typename T>
class Stack{
    public:
        Stack();
        Stack(int size);
        ~Stack();
        Stack(const Stack &t);
        bool IsEmpty();
        void Push(T t);
        T Pop();

    protected:
        void Resize();

    private:
        T *pdata_;
        int length_;
        int top_;
};
template <typename T>
Stack<T>::Stack(const Stack &t){
    length_ = t.length_;
    top_ = t.top_;
    pdata_ = new T [length_];
    for(int i = 0;i <= top_; i++)
        pdata_[i] = t.pdata_[i];
}
template <typename T>
Stack<T>::Stack(){
    length_ = 1;
    pdata_ = new T[length_];
    top_ = 0;
}
template <typename T>
Stack<T>::Stack(int length){
    pdata_ = new T[length];
    top_ = 0;
    length_ = length;
}
template <typename T>
Stack<T>::~Stack(){
    if(pdata_ != NULL){
        delete [] pdata_;
        pdata_ = NULL;
    }
    length_ = 0;
}
template <typename T>
bool Stack<T>::IsEmpty(){
    return !top_;
}
template<typename T>
void Stack<T>::Push(T t){
    if(top_ < length_ - 1){
        top_++;
        pdata_[top_] = t;
    }
    else{
        Resize();
        top_++;
        pdata_[top_] = t;
    }
}
template <typename T>
void Stack<T>::Resize(){
    int length = 2*length_;
    T *ptmp = new T[length];
    for(int i = 0; i < length_; i++)
        ptmp[i] = pdata_[i];
    length_ = length;
    pdata_ = ptmp;
}
template <typename T>
T Stack<T>::Pop(){
    return pdata_[top_--];
}
int main(){
    Stack<int> S1;
    for(int i = 0; i < 15; i++)
        S1.Push(i);
    Stack<int> S2 = S1;
    S2.Push(100);
    while(!S2.IsEmpty()){
        cout<<S2.Pop()<<" ";
    }
    cout<<endl;
    return 0;
}


