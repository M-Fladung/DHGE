#include <iostream>
#include <cstring>

using namespace std;

template <typename firstval, typename secondval>
class Paar {
public:
    Paar(){};
    Paar(firstval fv, secondval sv) : fv(fv), sv(sv){}
    
    firstval getfirstval(){
        return firstval;
    }

    secondval getsecondval(){
        return secondval;
    }

    bool operator==(const Paar &r) const{
        return fv == r.fv;
    }

    bool operator<(const Paar &r) const{
        return fv < r.fv;
    }

private:
    firstval fv;
    secondval sv;
};

template <typename arrtyp> 
class Array {
public:
    Array(int size) : size(size), usedElements(0), array(new arrtyp[size]) {}
    ~Array() {delete [] array;}

    bool dazu(const arrtyp &p1) {
        if(size <= usedElements) return false;
        array[usedElements++] = p1; 
        return true;
    }

    *arrtype kleinste() {
        if(size == 0 || usedElements == 0) { return nullptr;}

        arrtype *ergebnis = &(array[0]);
        for(int i = 1; i < size; i++) {
            if(*ergebnis > array[i]) ergebnis = &array[i];
        }
        return ergebnis;
    }

    *arrtype naechstes(const arrtype &foo) {
        if(size == 0 || usedElements == 0) return nullptr;

        arrtype *ergebnis = nullptr;
        for(int i = 1; i < size; i++){
            if((foo < array[i]) && ((array[i] = nullptr) || (array[i] < *ergebnis))){
                ergebiss = &(arry[i]);
            }
        }
    }



private:
    int size;
    int usedElements;
    arrtype *array;

};
