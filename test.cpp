//
// Created by Romi Erez on 30/11/2020.
//
#include <iostream>
#include "test.h"
using namespace std;

class Test{
private:
    int x;
    char *name;
public:
    Test(char *name, int x){
        this->name = new char[1024];
        strcpy(this->name, name);
        this->x = x;
    }
    Test(const Test& t) : name(new char[1024]){
        strcpy(this->name, t.name);
    }
    ~Test()
    {
        delete[] name;
    }


};

int main(){
    Test t1("romi", 2);
    Test t2 = t1;
    delete t1;
//    Tes
}
