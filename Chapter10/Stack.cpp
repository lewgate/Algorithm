#include <stdlib.h>
template <typename T>
class Stack{
    public:
        Stack();
        Stack(int size);
        ~Stack();
        bool IsEmpty();
        void Push(T t);
        bool Pop(T &t);
    protected:
        void Resize();

    private:
        T *pdata_;
        int length_;
        int top_;
};
template <typename T>
Stack<T>::Stack(){
    pdata_ = NULL;
    top_ = 0;
    length_ = 0;
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
bool Stack<T>::Pop(T &t){
    if(!IsEmpty()){
        t = pdata_[top_--];
        return true;
    }
    else
        return false;
}


