/* 6-3 problem of <<Introduction to Algorithms>>
 * try to apply Google C++ Guide Style
 */
#include <iostream>
template <typename T>
void Swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}
template <typename T>
class Young{
    public:
        Young(int width, int height);
        Young(int width, int height, T *data, int length);
        Young(Young<T> & Y);
        ~Young();
    public:
        int get_height()const{return height_;}
        int get_width() const{return width_;}
        T GetElement(int x, int y);
        void SetElement(int x, int y, T element);
        char GetMap(int x, int y);
        void SetMap(int x, int y, char data);
        T ExactMin();
        void InsertElement(T element);
        void PrintMax();

    private:
        int height_;
        int width_;
        T *pdata_;
        char *validmap_;
};
template <typename T>
void Young<T>::InsertElement(T element){
    int index = -1;
    for(int i = 0; i < width_*height_; i++)
        if(!validmap_[i]){
            index = i;
            break;
        }
    if(index == -1){
        // reallocate meomory
    }
    else{
        validmap_[index] = 1;
        pdata_[index] = element;
        while(index != 0){
            if(index%width_ != 0 && index/width_ != 0){
                T max;
                int maxid;
                if(pdata_[index-1] > pdata_[index-width_]){
                    max = pdata_[index-1];
                    maxid = index-1;
                }
                else{
                    max = pdata_[index-width_];
                    maxid = index-width_;
                }
                if(max > pdata_[index]){
                    Swap(pdata_[maxid], pdata_[index]);
                    index = maxid;
                }
                else
                    break;
            }
            else if(index%width_ != 0 && index/width_ == 0){
                    if(pdata_[index-1]>pdata_[index]){
                        Swap(pdata_[index-1], pdata_[index]);
                        index--; 
                    }
                else
                    break;
            }
            else if(index%width_ == 0 && index/width_ != 0){
                    if(pdata_[index-width_] > pdata_[index]){
                        Swap(pdata_[index-width_], pdata_[index]);
                        index = index - width_;
                    }
                    else
                        break;
            }
        }
    }
}



template <typename T>
void Young<T>::PrintMax(){
    for(int i = 0; i < height_; i++){
        for(int j = 0; j < width_; j++){
            if(validmap_[i*width_+j])
                std::cout<<pdata_[i*width_+j]<<" ";
            else
                std::cout<<"- ";
        }
        std::cout<<std::endl;
    }
}
template <typename T>
Young<T>::~Young(){
    delete [] pdata_;
    delete [] validmap_;
}
template <typename T>
char Young<T>::GetMap(int x, int y){
    return validmap_[y*width_+x];
}
template <typename T>
void Young<T>::SetMap(int x, int y, char data){
    validmap_[y*width_+x] = data;
}
template <typename T>
T Young<T>::GetElement(int x, int y){
    if(validmap_[y*width_+x])
        return pdata_[y*width_+x];
    else
        return (T)-1;
}
template <typename T>
void Young<T>::SetElement(int x, int y, T element){
    if(!validmap_[y*width_+x]){
        validmap_[y*width_+x] = 1;
        pdata_[y*width_+x] = element;
    }
    else
        pdata_[y*width_+x] = element;
}
template <typename T>
Young<T>::Young(Young<T> &Y){
    if(this != Y){
        height_ = Y.get_height();
        width_  = Y.get_width();
        delete [] pdata_;
        pdata_ = new T[height_*width_];
        delete [] validmap_;
        validmap_ = new char[height_*width_];
        for(int i = 0; i < width_*height_; i++)
            validmap_[i] = 0;
        for(int i = 0; i < width_; i++)
            for(int j = 0; j < height_; j++){
                SetElement(i, j, Y.GetElement(i, j));
                SetMap(i, j, Y.GetMap(i, j));
            }
    }
}
template <typename T>
Young<T>::Young(int width, int height){
    if(height > 0 && width > 0){
        height_ = height;
        width_ = width;
        pdata_ = new T[height*width];
        validmap_ = new char[height*width];
    }
    for(int i = 0; i < width*height; i++)
        validmap_[i] = 0;
}
template <typename T>
Young<T>::Young(int width, int height, T *data, int length){
    if(height > 0 && width > 0 && data != NULL ){
        height_ = height;
        width_ = width;
        pdata_ = new T[height*width];
        validmap_ = new char[height*width];
        for(int i = 0; i < width*height; i++)
            validmap_[i] = 0;
        for(int i = 0; i < length; i++){
            pdata_[i] = data[i];
            validmap_[i] = 1;
        }
    }
}
template <typename T>
T Young<T>::ExactMin(){
    int i = 0;
    if(validmap_[i] == 0)
        return (T)-1;
    T result = pdata_[i];
    while(((i+1)%width_&& validmap_[i+1])||((i/width_!=height_-1)&&(validmap_[i+width_]))){
        if((i+1)%width_==0){
            pdata_[i] = pdata_[i+width_];
            i += width_;
            continue;
        }
        else if(i/width_==height_-1){
            pdata_[i] = pdata_[i+1];
            i++;
            continue;
        }
        else if(validmap_[i+1]&&validmap_[i+width_]){
            if(pdata_[i+1] < pdata_[i+width_]){
                pdata_[i] = pdata_[i+1];
                i++;
                continue;
            }
            else{
                pdata_[i] = pdata_[i+width_];
                i += width_;
                continue;
            }
        }
        else if(validmap_[i+1] && ! validmap_[i+width_]){
                pdata_[i] = pdata_[i+1];
                i++;
                continue;
        }
        else{
            pdata_[i] = pdata_[i+width_];
            i += width_;
            continue;
        }
    }
    validmap_[i] = 0;
    return result;
}
int main(){
    int array[] = {2, 3, 4, 5, 8, 9, 12, 14, 16};
    Young<int> YMat(4, 4, array, 9);
    YMat.PrintMax();
    for(int i = 0; i < 9; i++){
        std::cout<<YMat.ExactMin()<<std::endl;
        YMat.PrintMax();
    }
    for(int i = 0; i < 9; i++){
        YMat.InsertElement(10-i);
        YMat.PrintMax();
        std::cout<<"*****************"<<std::endl;
    }
    return 0;
}
