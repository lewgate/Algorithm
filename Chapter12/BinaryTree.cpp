#include <iostream>
#include "../Chapter10/Stack.cpp"
using namespace std;
template <class T>
struct Node{
    Node<T> *pleft;
    T        key;
    Node<T> *pright;
    Node(const T &t = T(), Node<T> *ppleft = 0, Node<T> *ppright = 0):
        key(t), pleft(ppleft), pright(ppright){}
};
template <class T>
class BinaryTree{
    public:
        BinaryTree();
        BinaryTree(const BinaryTree<T> &t);
        ~BinaryTree();
        void Insert(const T &t);
        void Delete(const T &t);
        Node<T>* Search(const T &t);
        void InorderPrint();
        void PreorderPrint();
        void PostorderPrint();
        void InorderNoRec();
        Node<T>* FindMin();
        Node<T>* FindMax();
        void MakeEmpty();
    protected:
        void Insert(Node<T> *&root, const T &t);
        Node<T> *Search(Node<T> *root, const T &t);
        void InorderPrint(Node<T> *root);
        void PreorderPrint(Node<T> *root);
        void PostorderPrint(Node<T> *root);
        void Delete(Node<T> *&root, const T &t);
        Node<T>* FindMax(Node<T> *root);
        Node<T>* FindMin(Node<T> *root);
        void MakeEmpty(Node<T> *root);
    private:
        Node<T> *root_;
};
template <class T>
BinaryTree<T>::BinaryTree(){
    root_ = 0;
}
template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &t){
}
template <class T>
BinaryTree<T>::~BinaryTree(){
    MakeEmpty();
}
template <class T>
void BinaryTree<T>::MakeEmpty(){
    MakeEmpty(root_);
}
template <class T>
void BinaryTree<T>::MakeEmpty(Node<T> *root){
    if(root == 0)
        return;
    MakeEmpty(root->pleft);
    MakeEmpty(root->pright);
    delete root;
}
template <class T>
void BinaryTree<T>::Insert(Node<T> *&root, const T &t){
    if(root == 0){
        root = new Node<T>(t);
        return ;
    }
    if( t <= root->key)
        Insert(root->pleft, t);
    else
        Insert(root->pright, t);
    return ;
}

template <class T>
void BinaryTree<T>::Insert(const T &t){
    Insert(root_, t);
}
template <class T>
Node<T>* BinaryTree<T>::Search(Node<T> *root, const T &t){
    if(root == 0)
        return 0;
    if(root->key == t)
        return root;
    else if(root->key > t)
        return Search(root->pleft, t);
    else
        return Search(root->pright, t);
}
template <class T>
Node<T>* BinaryTree<T>::Search(const T &t){
    return Search(root_, t);
}
template <class T>
void BinaryTree<T>::InorderPrint(Node<T> *root){
    if(root != 0){
        InorderPrint(root->pleft);
        cerr<<" "<<root->key<<" ";
        InorderPrint(root->pright);
    }
    return ;
}
template <class T>
void BinaryTree<T>::PreorderPrint(Node<T> *root){
    if(root != 0){
        cerr<<" "<<root->key<<" ";
        PreorderPrint(root->pleft);
        PreorderPrint(root->pright);
    }
    return ;
}
template <class T>
void BinaryTree<T>::PostorderPrint(Node<T> *root){
    if(root != 0){
        PostorderPrint(root->pleft);
        PostorderPrint(root->pright);
        cerr<<" "<<root->key<<" ";
    }
    return ;
}
template <class T>
void BinaryTree<T>::InorderPrint(){
    InorderPrint(root_);
}
template <class T>
void BinaryTree<T>::PreorderPrint(){
    PreorderPrint(root_);
}
template <class T>
void BinaryTree<T>::PostorderPrint(){
    PostorderPrint(root_);
}
template <class T>
void BinaryTree<T>::InorderNoRec(){
    Stack<Node<T>*> s;
    Node<T> *p = root_;
    do{
        while(p != 0){
            s.Push(p);
            p = p->pleft;
        }
        if(!s.IsEmpty()){
            p = s.Pop();
            cerr<<" "<<p->key<<" ";
            p = p->pright;
        }
    }while(p != 0 || !s.IsEmpty());

}
template <class T>
void BinaryTree<T>::Delete(const T &t){
    Delete(root_, t);
}
template <class T>
void BinaryTree<T>::Delete(Node<T> * &root, const T &t){
    if(root == 0)
        return ;
    if(t > root->key)
        Delete(root->pright, t);
    else if(t < root->key)
        Delete(root->pleft, t);
    else if(root->pleft != 0 && root->pright != 0){
        root->key = FindMax(root->pright)->key;
        Delete(root->pright, t);
    }
    else{
        Node<T> *p = root;
        root = (root->pleft != 0)? root->pleft : root->pright;
        p->pleft = 0;
        p->pright = 0;
        delete p;
    }
    return ;
}
template <class T>
Node<T>* BinaryTree<T>::FindMax(Node<T> *root){
    if (root == 0)
        return 0;
    if (root->pright != 0)
        return FindMax(root->pright);
    else
        return root;
}
template <class T>
Node<T>* BinaryTree<T>::FindMin(Node<T> *root){
    if (root == 0)
        return 0;
    if (root->pleft != 0)
        return FindMin(root->pleft);
    else
        return root;
}
template <class T>
Node<T>* BinaryTree<T>::FindMax(){
    return FindMax(root_);
}
template <class T>
Node<T>* BinaryTree<T>::FindMin(){
    return FindMin(root_);
}

int main(){
    BinaryTree<int> tr;
    for(int i = 0; i < 15; i++)
        tr.Insert(i);
    tr.InorderNoRec();
    cerr<<"\n***********\n";
    tr.PostorderPrint();
    cerr<<"\n***********\n";
    tr.PreorderPrint();
    cerr<<"\n***********\n";
    for(int i = -1; i < 30; i++){
        Node<int> *p = tr.Search(i);
        if(p != 0)
            cerr<<p->key<<endl;
    }
    cout<<endl;
    for(int i = -2; i < 10; i++){
        tr.Delete(i);
        cerr<<"delete %d:"<<i;
        tr.InorderPrint();
        cerr<<endl;
    }
    return 0;
}


