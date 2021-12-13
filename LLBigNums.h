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
        BigNum(const BigNum* number);
        virtual ~BigNum();
        void setPrev(BigNum* bn);
        void setNext(BigNum* bn);
        BigNum* getPrev() {return prev;}
        BigNum* getNext() {return next;}
        int getValue() {return value;}
        //void append(const int number);
        BigNum operator +(const int number);
        BigNum operator *(const int number);
        //BigNum operator *(const BigNum number);
        //BigNum operator +(const BigNum number);
        std::string toString();

};

#endif