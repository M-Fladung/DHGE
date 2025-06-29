// Einfache Array-Klasse, Array-Klasse mit Zugriffszähler
//
// Klaus Kusche, 2011

#include <iostream>
// wir verwenden pow
#include <cmath>

using namespace std;

class Array
{
public:
    Array()
    {
        arr = new double[arrsize];
    }

    ~Array()
    {
        delete (arr); // oder free?
    }

    virtual int getSize();
    virtual bool setVal(uint index, double value);
    virtual double getVal(uint index);
    virtual void setAll(double value);
    void print();

public:
    int arrsize;
    double *arr;
};

    int Array::getSize()
    {
        return arrsize;
    }

    double Array::getVal(uint index)
    {
        if (index > arrsize || index < 0)
        {
            return 0;
        }
        else
        {
            return arr[index];
        }
    }

    bool Array::setVal(uint index, double value)
    {
        if (index > arrsize || index < 0)
        {
            return false;
        }
        arr[index] = value;
        if(arr[index] != value){
            return false;
        }else{
            return true;
        }
    }

    void Array::setAll(double value){
        for(int i = 0; i < arrsize; i++){
            arr[i] = value;
        }
    }

    void Array::print(){
        for(int i = 0; i < arrsize; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

class StatArray : public Array
{
        StatArray()
    {
        arr = new double[arrsize];
    }

    ~StatArray()
    {
        delete (arr); // oder free?
    }

    
};

StatArray Accumulate(StatArray a);

int main()
{
    StatArray *a = new StatArray(12);

    a->setAll(1);
    cout << "a am Anfang: ";
    a->print();

    StatArray b = *a;

    cout << "b am Anfang: ";
    b.print();

    for (unsigned int i = 0; i < b.getSize(); ++i)
    {
        b.setVal(i, pow(2, i));
    }

    a->setVal(0, 0);
    cout << "a nach " << a->getWriCnt() << " Änderungen: ";
    a->print();
    delete a;

    StatArray c = b;
    cout << "b nach " << b.getWriCnt() << " Änderungen: ";
    b.print();
    cout << "Kopie davon (" << c.getWriCnt() << " Änderungen): ";
    c.print();

    StatArray d = Accumulate(b);
    cout << "Ergebnis von Accumulate (" << d.getWriCnt() << " Änderungen): ";
    d.print();

    cout << "b nach Accumulate (" << b.getWriCnt() << " Änderungen): ";
    b.print();

    return 0;
}

// Returniere ein neues Array-Objekt, in dem das i-te Element
// die Summe aller Elemente bis incl. i-tem Element im alten Array ist
// Parameter a wird "by Value" übergeben
// ==> a ist eine Kopie des Array-Objektes im Aufrufer
// und kann lokal modifiziert werden
StatArray Accumulate(StatArray a)
{
    double sum = 0;

    for (unsigned int i = 0; i < a.getSize(); ++i)
    {
        sum += a.getVal(i);
        a.setVal(i, sum);
    }

    return a;
}