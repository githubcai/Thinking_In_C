template<typename T>
void f(T*){}

void h(void (*pf)(int*)){}

template<typename T>
void g(void (*pf)(T*)){}

int main(){
    h(&f<int>);
    h(&f);
    g<int>(&f<int>);
    g(&f<int>);
    g<int>(&f);
}
