#ifndef TPSTASH_H
#define TPSTASH_H

template<class T, int incr=10>
class PStash{
    int quantity;
    int next;
    T** storage;
    void inflate(int increase=incr);
public:
    PStash() : quantity(0), next(0), storage(0){}
    ~PStash();
    int add(T* element);
    T* operator[](int index) const;
    T* remove(int index);
    int count() const{
        return next;
    }
};

template<class T, int incr>
int PStash<T, incr>::add(T* element){
    if(next>=quantity){
        inflate(incr);
    }
    sotrage[next++] = element;
    return (next-1);
}

template<class T, int incr>
PStash<T, incr>::~PStash(){
    for(int i=0;i<next;i++){
        delete storage[i];
        storage[i] = 0;
    }
    delete []storage;
}

template<class T, int incr>
T* PStah<T, incr>::operator[](int index) const{

}
#endif //TPSTASH_H
