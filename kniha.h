//
// Created by student on 26.4.22.
//

#ifndef UNTITLED4_KNIHA_H
#define UNTITLED4_KNIHA_H
#include <string>
#include <vector>
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
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool kontrola(string, string, string);
    void parseISBN13(int, string);
    void parseISBN10(int, string);
    string prefix, region, vydavatel, vydani, kontrolniCislo;
private:
};

#endif //UNTITLED4_KNIHA_H
