//LLBigNums.h

#ifndef __LLBigNums_h__
#define __LLBigNums_h__

#include<iostream>
#include<string>

/**
 * @brief NumSlice is a node struct containing the value of the 1000s slice, 
 * as well as pointers to the previous and next nodes
 * 
 */
struct NumSlice {

    NumSlice *next;
    NumSlice *prev;
    int value;

};

/**
 * @brief BigNum is a class to represent big numbers in c++
 * 
 */
class BigNum {
    
    private:

        // base is the NumSlice at the 1000^0th position
        NumSlice *base;

    public:

        BigNum();
        BigNum(int num);
        BigNum(NumSlice *ns);
        BigNum(const BigNum* bn);
        BigNum(const BigNum& bn);
        ~BigNum();
        BigNum operator +(const int add);
        BigNum operator + (const BigNum& bn);
        BigNum operator *(const int number);
        BigNum operator *(const BigNum& number);
        BigNum multiplyHelper(NumSlice* ns, int counter);
        void operator =(const BigNum &toAss);
        std::string toString();

        friend std::ostream& operator<<(std::ostream& os, const BigNum& number);

};

#endif