#ifndef NUMSTRINGGEN_H
#define NUMSTRINGGEN_H
#include <cstdlib>
#include <cstring>

class NumStringGen{
    const int sz;
public:
    NumStringGen(int ssz=5) : sz(ssz){}
    std::string operator()(){
        std::string digits("0123456789");
        const int ndigits=digits.size();
        std::string r(sz, ' ');
        r[0] = digits[std::rand()%(ndigits-1)]+1;
        for(int i=1;i<sz;i++){
            if(sz>=3 && i==sz/2){
                r[i] = '.';
            }else{
                r[i] = digits[std::rand()%ndigits];
            }
        }
        return r;
    }
};

#endif // NUMSTRINGGEN_H
