#include<iostream>
#include<string>

using namespace std;

struct NumSlice {
    NumSlice *next;
    NumSlice *prev;
    int num;
};

class BigNum {
    private:
        NumSlice *base;

    public:
        BigNum();
        BigNum(int num);
        BigNum(NumSlice *ns);
        ~BigNum();
        void fix();
        BigNum operator *(const int mul);
        //BigNum operator *(const BigNum mul);
        string toString();

};

BigNum::BigNum() {
    base = new NumSlice;
    base->next = nullptr;
    base->prev = nullptr;
    base->num = 0;
}

BigNum::BigNum(int num) {
    base = new NumSlice;
    base->prev = nullptr;
    base->next = nullptr;
    base->num = num;
    fix();
}

BigNum::BigNum(NumSlice *ns) {
    base = ns;
}

BigNum::~BigNum() {
    
}

void BigNum::fix() {
    NumSlice* current = base;

    while (nullptr != current) {

        if (current->num >= 1000) {

            int numToPush = current->num / 1000;
            current->num -= (numToPush*1000);

            if (nullptr == current->next) {
                NumSlice *newSlice = new NumSlice;
                newSlice->num = numToPush;
                newSlice->prev = current;
                newSlice->next = nullptr;
                current->next = newSlice;
            } else {
                current->next->num += numToPush;
            }

        }

        current = current->next;

    }

}

BigNum BigNum::operator *(const int mul) {

    NumSlice *current = base;

    while (nullptr != current) {
        current->num *= mul;
        current = current->next;
    }

    fix();

    return BigNum(base);

}

string BigNum::toString() {

    NumSlice *current = base;
    string out = "";

    while (nullptr != current->next) {
        current = current->next;
    }

    while (nullptr != current) {
        if (current->num < 10)
            out += "00" + to_string(current->num) + " ";
        else if (current-> num < 100)
            out += "0" + to_string(current->num) + " ";
        else 
            out += to_string(current->num) + ' ';
        current = current->prev;
    }

    return out;

}

BigNum factorial(int n) {
    BigNum out(1);
    for (int i = 1; i <= n; i++) {
        out = out*i;
    }
    return out;
}

int main(int argc, char* argv[]) {
    int fac = 100;
    if (argc == 2) {
        fac = atoi(argv[1]);
    }

    BigNum test(123456789);
    cout << test.toString() << endl;

    test = test*10;
    cout << test.toString() << endl;

    cout << fac << "! = " << factorial(fac).toString() << endl;

    return 0;
    
}