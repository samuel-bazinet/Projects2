#include<iostream>
#include<string>

using namespace std;

struct NumSlice {
    NumSlice *next;
    NumSlice *prev;
    int value;
};

void add(NumSlice* slice, int number) {
    slice->value += number;

    if (slice->value >= 1000) {

        int toAdd = slice->value/1000;
        slice->value -= toAdd*1000;

        if (nullptr == slice->next) {

            NumSlice *newSlice = new NumSlice;
            newSlice->prev = slice;
            newSlice->value = 0;
            newSlice->next = nullptr;
            slice->next = newSlice;

        }

        add(slice->next, toAdd);
        
    }

}

void multiply(NumSlice* slice, int number) {

    slice->value *= number;

    if (nullptr != slice->next) {
        multiply(slice->next, number);
    }

    if (slice->value >= 1000) {

        int toAdd = slice->value/1000;
        slice->value -= toAdd*1000;

        if (nullptr == slice->next) {

            NumSlice *newSlice = new NumSlice;
            newSlice->prev = slice;
            newSlice->value = 0;
            newSlice->next = nullptr;
            slice->next = newSlice;

        }

        add(slice->next, toAdd);
        
    }
    
}

class BigNum {
    private:
        NumSlice *base;

    public:
        BigNum();
        BigNum(int num);
        BigNum(NumSlice *ns);
        BigNum(const BigNum* bn);
        BigNum(const BigNum& bn);
        ~BigNum();
        void fix();
        BigNum operator +(const int add);
        BigNum operator + (const BigNum& bn);
        BigNum operator *(const int mul);
        //BigNum operator *(const BigNum mul);
        void operator =(const BigNum &toAss);
        string toString();

};

BigNum::BigNum() {
    base = new NumSlice;
    base->next = nullptr;
    base->prev = nullptr;
    base->value = 0;
}

BigNum::BigNum(int num) {
    base = new NumSlice;
    base->prev = nullptr;
    base->next = nullptr;
    base->value = num;
    if (base->value >= 1000) {
        int toAdd = base->value/1000;
        base->value -= toAdd*1000;
        NumSlice *newSlice = new NumSlice;
        newSlice->prev = base;
        newSlice->value = 0;
        newSlice->next = nullptr;
        base->next = newSlice;
        add(newSlice, toAdd);
    }
}

BigNum::BigNum(NumSlice *ns) {
    base = new NumSlice;
    base->prev = nullptr;
    base->next = nullptr;
    base->value = ns->value;
    NumSlice *temp1 = base;
    NumSlice *temp2 = ns;
    while (nullptr != temp2->prev) {
        temp1->prev = new NumSlice;
        temp1->prev->next = temp1;
        temp1 = temp1->prev;
        temp2 = temp2->prev;
        temp1->value = temp2->value;
    }
    temp1->prev = nullptr;
    temp1 = base;
    temp2 = ns;
    while(nullptr != temp2->next) {
        temp1->next = new NumSlice;
        temp1->next->prev = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
        temp1->value = temp2->value;
    }
    temp1->next = nullptr;

}

BigNum::BigNum(const BigNum* bn) {
    NumSlice *temp2 = bn->base;
    base = new NumSlice;
    base->prev = nullptr;
    base->next = nullptr;
    base->value = temp2->value;
    NumSlice *temp1 = base;
    while (nullptr != temp2->prev) {
        temp1->prev = new NumSlice;
        temp1->prev->next = temp1;
        temp1 = temp1->prev;
        temp2 = temp2->prev;
        temp1->value = temp2->value;
    }
    temp1->prev = nullptr;
    temp1 = base;
    temp2 = bn->base;
    while(nullptr != temp2->next) {
        temp1->next = new NumSlice;
        temp1->next->prev = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
        temp1->value = temp2->value;
    }
    temp1->next = nullptr;
}

BigNum::BigNum(const BigNum& bn) {
    NumSlice *temp2 = bn.base;
    base = new NumSlice;
    base->prev = nullptr;
    base->next = nullptr;
    base->value = temp2->value;
    NumSlice *temp1 = base;
    while (nullptr != temp2->prev) {
        temp1->prev = new NumSlice;
        temp1->prev->next = temp1;
        temp1 = temp1->prev;
        temp2 = temp2->prev;
        temp1->value = temp2->value;
    }
    temp1->prev = nullptr;
    temp1 = base;
    temp2 = bn.base;
    while(nullptr != temp2->next) {
        temp1->next = new NumSlice;
        temp1->next->prev = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
        temp1->value = temp2->value;
    }
    temp1->next = nullptr;
}

BigNum::~BigNum() {
    NumSlice *current = base;
    while (nullptr != current->next) {
        current = current->next;
    }
    while (nullptr != current->prev) {
        current = current->prev;
        delete current->next;
    }
    delete current;
}

BigNum BigNum::operator+(const int number) {
    
    BigNum returnNum(this);
    NumSlice *current = returnNum.base;
    
    add(current, number);

    return returnNum;
    
}

BigNum BigNum::operator+(const BigNum& bn) {

    BigNum returnNum(this);
    NumSlice *leftSlice = returnNum.base;
    NumSlice *rightSlice = bn.base;

    while (nullptr != rightSlice->next) {

        add(leftSlice, rightSlice->value);

        if (nullptr == leftSlice->next) {

            NumSlice *newSlice = new NumSlice;
            newSlice->prev = leftSlice;
            newSlice->value = 0;
            newSlice->next = nullptr;
            leftSlice->next = newSlice;

        }

        leftSlice = leftSlice->next;
        rightSlice = rightSlice->next;

    }

    add(leftSlice, rightSlice->value);

    return returnNum;

}

// TODO make sure u only go through it once
BigNum BigNum::operator *(const int number) {

    BigNum returnNum(this);
    NumSlice *current = returnNum.base;

    multiply(current, number);

    return returnNum;

}

void BigNum::operator =(const BigNum &toAss) {
    base = new NumSlice;
    base->prev = nullptr;
    base->value = toAss.base->value;
    base->next = nullptr;
    NumSlice *temp1 = base;
    NumSlice *temp2 = toAss.base;
    while (nullptr != temp2->next) {
        NumSlice *temp3 = new NumSlice;
        temp2 = temp2->next;
        temp3->prev = temp1;
        temp3->value = temp2->value;
        temp3->next = nullptr;
        temp1->next = temp3;
        temp1 = temp1->next;
    }
    temp1 = base;
    temp2 = toAss.base;
    while (nullptr != temp2->prev) {
        NumSlice *temp3 = new NumSlice;
        temp2 = temp2->prev;
        temp3->next = temp1;
        temp3->value = temp2->value;
        temp3->prev = nullptr;
        temp1->prev = temp3;
        temp1 = temp1->prev;
    }
}

string BigNum::toString() {

    NumSlice *current = base;
    string out = "";

    while (nullptr != current->next) {
        current = current->next;
    }

    while (nullptr != current) {
        if (current->value < 10)
            out += "00" + to_string(current->value) + " ";
        else if (current->value < 100)
            out += "0" + to_string(current->value) + " ";
        else 
            out += to_string(current->value) + ' ';
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
    cout << "Pre changes: " << test.toString() << endl;

    test = test+2345678;
    cout << "After addition with int(2345678): " << test.toString() << endl;

    test = BigNum(1000) + test;
    cout << "After addition with BigNum(1000): " << test.toString() << endl;

    test = test*10;
    cout << "After multiplication by int(10): " << test.toString() << endl;

    //cout << fac << "! = " << factorial(fac).toString() << endl;

    return 0;
    
}