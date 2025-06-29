#include <iostream>
#include <cstring>

using namespace std;

class String{
    public:
    String(uint size = 0) : txt(new char[size + 1]){
        txt[0]='\0';
    }

/** //sollte das gleiche sein wie der Konstruktor
    String(uint strlen = 0){
    txt = new char[strlen +1];
    txt[0]='\0';
    }
*/
    String(const String &orig) : txt(new char[strlen(orig.txt) + 1]){
        strcpy(txt, orig.txt);
    }

    String(const char *str) : txt(new char[strlen(str) + 1]){

    }

    ~String(){
        delete []txt;
    }

    private:
    char *txt; 
};

int main(int argc, char *argv[]){

}