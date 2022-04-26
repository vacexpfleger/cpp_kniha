//
// Created by student on 26.4.22.
//

#ifndef UNTITLED4_KNIHA_H
#define UNTITLED4_KNIHA_H
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class kniha{
public:
    kniha();
    kniha(string, string, string);
    kniha(const kniha &);
    void setDefault();
    string title;
    string author;
    string isbn;
    void print();
    bool kontrola(string);
private:
};

#endif //UNTITLED4_KNIHA_H
