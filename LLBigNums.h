//LLBigNums.h

#ifndef __LLBigNums_h__
#define __LLBigNums_h__

#include<iostream>
#include<string>

class BigNum {

    private:
        BigNum* prev;
        BigNum* next;
        int value;

    public:
        BigNum();
        BigNum(int number);
        void setPrev(BigNum* bn);
        void setNext(BigNum* bn);
        void append(int number);
        ~BigNum();
        //BigNum operator *(const int number);
        //BigNum operator *(const BigNum number);
        //BigNum operator +(const int number);
        //BigNum operator +(const BigNum number);
        std::string toString();

};

#endif