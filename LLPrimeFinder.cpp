#include<iostream>
#include<fstream>

using namespace std;

struct PrimeList {

    int curPrime;
    PrimeList* next;

};

int pow2(int toPow) {
    return toPow*toPow;
}

int main(int argc, char* argv[]) {

    PrimeList first;
    first.curPrime = 2;
    first.next = nullptr;

    PrimeList *current = &first;
    PrimeList *nextAdd = &first;
    PrimeList *end = &first;


    int maxIter = 1000;
    int comps = 0;

    if (argc == 2) {
        maxIter= atoi(argv[1]);
    }   

    for (int i = 3; i <= maxIter; i += 2) {

        cout << i << " Is the candidate" << endl;

        current = &first;

        comps++;
        if (i >= pow2(nextAdd->curPrime)) {
            nextAdd = nextAdd->next;
            cout << "nextAdd has been incremented" << endl;
        }

        
            
        bool isOut = false;

        while (nextAdd != current) {
            comps++;
            if (i % current->curPrime == 0) {
                cout << i << " is dividable by " << current->curPrime << endl;
                cout << i << " Is out" << endl;
                isOut = true;
                break;

            }

            cout << i << " is not dividable by " << current->curPrime << endl;

            current = current->next;
            
        }

        if (isOut) {
            cout << endl;
                continue;
        }
        
        
        
        PrimeList* newPrime = new PrimeList;
        newPrime->curPrime = i;
        newPrime->next = nullptr;
        end->next = newPrime;
        end = newPrime;

        cout << i << " is a prime" << endl << endl;

    }

    current = &first;
    int numPrimes = 0;

    cout << "The primes are:" << endl;

    while (nullptr != current) {
        cout << current->curPrime << endl;
        current = current->next;
        numPrimes++;
    }

    cout << "There are " << numPrimes << " primes under " << maxIter << endl;  
    cout << "This program took " << comps << " comparaisons" << endl;  

    return 0;
}