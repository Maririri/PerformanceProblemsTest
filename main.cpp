#include "slow_header.h"
#define M0 void foo(); void bar();
#define M1 M0 M0 M0 M0 M0
#define M2 M1 M1 M1 M1 M1
#define M3 M2 M2 M2 M2 M2
#define M6 M3 M3 M3 M3 M3
#define M7 M6 M6 M6 M6
#define M8 M7 M7 M7 M7
#define M9 M8 M8 M8 M8
M10


#include <iostream>


using namespace std;

class E {
public:
    const char* error;
    E(const char* arg) : error(arg) { };
};

class A {
public:
    A() try { throw E("Exception in A()"); }
    catch(E& e) { cout << "Handler in A(): " << e.error << endl; }
};

int f() try {
    throw E("Exception in f()");
    return 0;
}
catch(E& e) {
    cout << "Handler in f(): " << e.error << endl;
    return 1;
}

int main() {
    int i = 0;
    try { A cow; }
    catch(E& e) {
        cout << "Handler in main(): " << e.error << endl;
    }

    try { i = f(); }
    catch(E& e) {
        cout << "Another handler in main(): " << e.error << endl;
    }

    cout << "Returned value of f(): " << i << endl;
}

#include <cstdio>
using std::printf;

int global_argc;

struct A2{
    int _x;
    A2();
    A2(int);
};

A2::A2(int x):_x((printf("In A::A(int) initializer for A::_x.\n"),x)){
    printf("In A::A(int) constructor body.\n");

    if(global_argc % 2 !=0){
        printf("Will throw.\n");
        throw 0;
    }
    printf("Will not throw.\n");
}

A2::A2() try:A2((printf("In A::A() initializer for delegating to A::A(int).\n"),42)){
    printf("In A::A() function-try-block body.\n");
}
catch(...){
    printf("In catch(...) handler for A::A() function-try-block.\n");
}

int main2(int argc, char **argv){
    printf("In main().\n");
    global_argc = argc;
    try{
        A2 a;
        printf("Back in main().\n");
    }
    catch(...){
        printf("In catch(...) handler for try-block in main().\n");
    }
    return 0;
}

int main3() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct C{ int initl; int initn;

    C() ;
};
C::C()
try : initl(1), init(2)
{
    // Constructor
}
catch(...)
{
    // Handle exception
    printf("");
}