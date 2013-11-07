#include <iostream>
using namespace std;
template <typename T>
class Queue{
    public:
        Queue();
        Queue(int size);
        Queue(const Queue &q);
        ~Queue();
        void EnQueue(T t);
        T DeQueue();
        bool  IsEmpty();
        int Size();
    protected:
       void  Resize();
       bool  IsFull();
    private:
        T *pdata_;
        int length_;
        int head_;
        int tail_;
};
template <typename T>
int Queue<T>::Size(){
    return length_;
}
template <typename T>
Queue<T>::Queue(){
    length_ = 2;
    head_ = 0;
    tail_ = 0;
    pdata_ = new T[length_];
}
template <typename T>
Queue<T>::Queue(int size){
    length_ = size;
    head_ = 0;
    tail_ = 0;
    pdata_  = new T[length_];
}
template <typename T>
Queue<T>::Queue(const Queue &q){
    length_ = q.length_;
    head_   = q.head_;
    tail_   = q.tail_;
    pdata_ = new T[length_];
    for(int i = head_; i < tail_; i = (i++)%length_)
        pdata_[i] = q.pdata_[i];
}
template <typename T>
Queue<T>::~Queue(){
    length_ = 0;
    head_ = 0;
    tail_ = 0;
    delete [] pdata_;
}
template <typename T>
bool Queue<T>::IsFull(){
    if((tail_+1)%length_ == head_)
        return true;
    else
        return false;
}
template <typename T>
bool Queue<T>::IsEmpty(){
    if(head_ == tail_)
        return true;
    return false;
}
template <typename T>
void Queue<T>::EnQueue(T t){
    if(IsFull())
        Resize();
    pdata_[tail_] = t;
    tail_ = (tail_+1)%length_;
}
template <typename T>
T Queue<T>::DeQueue(){
    int tmp = head_;
    head_ = (tmp+1)%length_;
    return pdata_[tmp];
}
template <typename T>
void Queue<T>::Resize(){
    int oldlength = length_;
    int oldhead = head_;
    int oldtail = tail_;
    length_ *=2;
    T *ptmp = new T[length_];
    head_ = 0;
    tail_ = 0;
    for(int i = oldhead; i < oldtail; i = (i++)%oldlength)
        ptmp[tail_++] = pdata_[i];
    delete [] pdata_;
    pdata_ = ptmp;
}
int main(){
    Queue<int> q1;
    for(int i = 0; i < 14; i++)
        q1.EnQueue(i);
    cout<<q1.Size()<<endl;
    for(int i = 0; i < 10; i++)
        cout<<q1.DeQueue()<<" ";
    cout<<endl;
    for(int i = 100;i<108; i++)
        q1.EnQueue(i);
    cout<<q1.Size()<<endl;
    while(!q1.IsEmpty())
        cout<<q1.DeQueue()<<" ";
    cout<<endl;
    return 0;
}
    

