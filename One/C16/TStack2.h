#ifndef TSTACK2_H
#define TSTACK2_H
#include "../require.h"

template<class T> 
class Stack{
    struct Link{
        T* data;
        Link* next;
        Link(T* dat, Link* nxt):data(dat), next(nxt){}
    }* head;
public:
    Stack() : head(0){}
    ~Stack();
    void push(T* dat){
        head = new Link(dat, head);
    }
    T* peek() const{
        return head ? head->data : 0;
    }
    T* pop();
    class Iterator;
    friend class Iterator;
    class Iterator{
        Stack::Link* p;
    public:
        Iterator(const Stack<T>& t1) : p(t1.head){}
        Iterator(const Iterator& t1) : p(t1.p){}
        Iterator() : p(0){}
        bool operator++(){
            if(p->next){
                p = p->next;
            }else{
                p = 0;
            }
            return bool(p);
        }
        bool operator++(int){
            return operator++();
        }
        T* current() const{
            if(!p){
                return 0;
            }
            return p->data;
        }
        T* operator->() const{
            require(p!=0, "PStack::iterator::operator->returns 0");
            return current();
        }
        T* operator*() const{
            return current();
        }
        operator bool() const{
            return bool(p);
        }
        bool operator==(const Iterator&) const{
            return p==0;
        }
        bool operator!=(const Iterator&) const{
            return p!=0;
        }
    };
    Iterator begin() const{
        return Iterator(*this);
    }
    Iterator end() const{
        return Iterator();
    }
};

template<class T> Stack<T>::~Stack(){
    while(head){
        delete pop();
    }
}

template<class T>
T* Stack<T>::pop(){
    if(head==0){
        return 0;
    }
    T* result = head->data;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
}

#endif // TSTACK2_H
