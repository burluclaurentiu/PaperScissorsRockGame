// Joc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Varianta {
public:
    virtual int joc(Varianta* v) = 0;
    virtual int contraHartie() = 0;
    virtual int contraPiatra() = 0;
    virtual int contraFoarfeca() = 0;
};

class Piatra : public Varianta {
public:
    int contraHartie(){
        return 1;
    }
    int contraPiatra() {
        return 0;
    }
    int contraFoarfeca() {
        return -1;
    }
    int joc(Varianta* v) {
        return v->contraPiatra();
    }
};

class Foarfeca : public Varianta {
public:
    int contraHartie(){
        return -1;
    }
    int contraPiatra() {
        return 1;
    }
    int contraFoarfeca() {
        return 0;
    }
    int joc(Varianta* v) {
        return v->contraFoarfeca();
    }
};

class Hartie : public Varianta {
public:
    int contraHartie(){
        return 0;
    }
    int contraPiatra() {
        return -1;
    }
    int contraFoarfeca() {
        return 1;
    }
    int joc(Varianta* v) {
        return v->contraHartie();
    }
};

int joaca(Varianta* v1, Varianta* v2) {
    return v1->joc(v2);
}

int main()
{
    Piatra p; Foarfeca f; Hartie h;
	cout << joaca(&p, &f) << endl;	// 1
	cout << joaca(&p, &p) << endl;	// 0
	cout << joaca(&h, &f) << endl;	// -1
	cout << joaca(&p, &h) << endl;	// -1
}
