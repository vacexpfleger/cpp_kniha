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
    kniha(const string&, const string&, const string&);
    kniha(const kniha &);
    kniha& operator=(const kniha &);
    bool operator==(const kniha &);
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool kontrola(const string&, const string&, const string&);
    void setKniha(const string &, const string &, const string &);
    string parseISBN13(int, string);
    string parseISBN10(int, string);
    string prefix, region, vydavatel, vydani, kontrolniCislo, vystup;
private:
    string title;
    string author;
    string isbn;
    void setDefault();
    bool validateIsbn10(string);
    bool validateIsbn13(string);
};

std::ostream & operator <<(std::ostream & , const kniha &);
#endif //UNTITLED4_KNIHA_H
