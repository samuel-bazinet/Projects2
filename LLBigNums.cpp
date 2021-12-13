#include"LLBigNums.h"

using namespace std;

BigNum::BigNum() {
    next = nullptr;
    prev = nullptr;
    value = 0;
}

BigNum::BigNum(int number) {
    if (number >= 1000) {
        int temp = number/1000;
        value = number - temp*1000;
    } else {
        value = number;
    }
    prev = nullptr;
    if (number >= 1000) {
        this->append(number/1000);
    } else {
        next = nullptr;
    }
}

BigNum::~BigNum() {
    
}

void BigNum::setPrev(BigNum* bn) {
    this->prev = bn;
}

void BigNum::setNext(BigNum* bn) {
    this->next = bn;
}

void BigNum::append(int number) {
    BigNum* newNum = new BigNum(number);
    newNum->setPrev(this);
    this->next = newNum;

}

string BigNum::toString() {

    BigNum* current = this;
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

int main() {

    BigNum test(123456789);

    cout << test.toString() << endl;

    return 0;
}