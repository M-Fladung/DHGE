#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Bruch
{
    friend ostream &operator<<(ostream &outFile, const Bruch &a);
    public:
    Bruch(int zaehler = 0, int nenner = 1) : z(zaehler), n(nenner) {
        Kuerze();
    }

    Bruch(const char *str);

    Bruch operator+(const Bruch &r) const {
        return Bruch(z * r.n + r.z * n, n * r.n);
    }

    Bruch operator-(const Bruch &r) const {
        return Bruch(z * r.n - r.z * n, n * r.n);
    }

    Bruch operator*(const Bruch &r) const {
        return Bruch(z * r.z, n * r.n);
    }

    Bruch operator/(const Bruch &r) const {
        return Bruch(z * r.n, n * r.z);
    }
    operator double() const {
        return double(z) / double(n);
    }

    private:
    int z;
    int n;

    void Kuerze();
};

Bruch::Bruch(const char *str)
{
    z = atoi(str);
    const char *p = strchr(str, '/');
    if(p == nullptr) 
    {
        n = 1;
    }else{
        n = atoi(p + 1);
        Kuerze();
    }
}

int ggT(int a, int b);

void Bruch::Kuerze()
{
    if(n == 0)
    {
        cerr << "Nenner ist 0!" << endl;
        exit(EXIT_FAILURE);
    }

    if(n < 0)
    {
        z = -z;
        n = -n;
    }

    int g = ggT(z, n);
    z /= g;
    n /= g;
}

int ggT(int a, int b)
{
    if(a < 0) a = -a;
    if(b < 0) b = -b;

    while(b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ostream &operator<<(ostream &outFile, const Bruch &a)
{
    if(a.n == 1) 
    {
        outFile << a.z;
    }else{
        outFile << a.z << '/' << a.n;
    }
    return outFile;
}

int main(int argc, const char *argv[])
{
    if(argc % 2 != 0)
    {
        cerr << argv[0] << ": Falsche Anzahl von Eingaben!\n "<< endl;
        exit(EXIT_FAILURE);
    }
    Bruch result(argv[1]);
    for(int i = 2; i < argc; i += 2)
    {
        Bruch input(argv[i + 1]);
        switch(argv[i][0])
        {
            case '+':
                result = result + input;
                break;
            case '-':
                result = result - input;
                break;
            case '*':
                result = result * input;
                break;
            case '/':
                result = result / input;
                break;
            default: 
                cerr << argv[0] << ": " << argv[i][0] << "Kein Rechenzeichen?" << endl;
                exit(EXIT_FAILURE);

        }
    }

    cout << "Ergebnis: " << result << endl;
    cout << "Als Kommazahlt: "<< double(result) << endl;

    exit(EXIT_SUCCESS);
}
