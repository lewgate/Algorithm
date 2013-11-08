#include <iostream>
template <typename T>
struct Node{
    Node<T> *prev;
    T key;
    Node<T> *next;
};
template <typename T>
class DoubleList{
    public:
        void Insert(const T x);
        void Delete(const T x);
        Node<T>* Search(const T x);
        DoubleList();
        ~DoubleList();
        void Print();
        Node<T> * operator[](int idx);
        int Size();
    private:
        Node<T>* phead_;
        int length_;
};
template <typename T>
DoubleList<T>::DoubleList(){
    phead_ = new Node<T>; 
    phead_->key = 0;
    phead_->prev = phead_;
    phead_->next = phead_;
    length_ = 0;
}
template <typename T>
DoubleList<T>::~DoubleList(){
    while(phead_->next != phead_){
        Node<T> *p = phead_->next;
        phead_->next->next->prev = phead_;
        phead_->next = phead_->next->next;
        delete p;
    }
    phead_->next = 0;
    phead_->prev = 0;
    delete phead_;

}
template <typename T>
void DoubleList<T>::Print(){
    Node<T> *p = phead_->next;
    while(p != phead_){
        std::cout<<p->key<<" ";
        p = p->next;
    }
    std::cout<<std::endl;
}
template <typename T>
int DoubleList<T>::Size(){
    return length_;
}
template <typename T>
void DoubleList<T>::Insert(const T x){
    Node<T> *p = new Node<T>;
    p->key = x;
    p->next = phead_->next;
    p->prev = phead_;
    phead_->next = p;
    p->next->prev = p;
    length_++;
}
template <typename T>
void DoubleList<T>::Delete(const T x){
    Node<T> *p = Search(x);
    if(p == 0)
        return;
    else{
        p->next->prev = p->prev;
        p->prev->next = p->next;
        delete p;
        length_--;
        return ;
    }

}
template <typename T>
Node<T>* DoubleList<T>::Search(const T x){
    Node<T> *result = phead_->next;
    while(result!= phead_){
        if(result->key == x)
            return result;
        result = result->next;
    }
    return 0;
}
template <typename T>
Node<T>* DoubleList<T>::operator[](int idx){
    if(idx < 0 || idx > length_-1)
        return 0;
    else{
        Node<T> *p = phead_->next;
        while(idx != 0){
            idx--;
            p = p->next;
        }
        return p;
    }
}
int main(){
    DoubleList<int> list;
    for(int i = 1; i < 10; i++)
        list.Insert(i);
    list.Print();
    for(int i = 1; i < 9; i++){
        list.Delete(i);
        std::cout<<list.Size()<<std::endl;
        list.Print();
    }
    list.Print();
    return 0;
}


