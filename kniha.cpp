#include <string>
#include <vector>
#include "kniha.h"

#define TITLE "The Glass Room"
#define AUTHOR "Simon Mawer"
#define ISBN "978-0-349-12132-1"

#define MIN_LENGTH 5
#define MAX_LENGTH 100

kniha::kniha() {
    setDefault();
}

kniha::kniha(string title, string author, string isbn) {
    if(!kontrola(title, author, isbn)){
        setDefault();
    }

    else {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
    }
}

bool kniha::kontrola(string title, string author, string isbn){
    size_t separatorCount = count_if( isbn.begin(), isbn.end(), []( char c ){return c =='-';});

    if(title.length() < MIN_LENGTH or title.length() > MAX_LENGTH){
        cout << "Neplatny nazev knihy." << endl;
        return false;
    }

    if(author.length() < MIN_LENGTH or author.length() > MAX_LENGTH){
        cout << "Neplatne jmeno autora." << endl;
        return false;
    }

    if(isbn.length() < 10 or isbn.length() > 17) {
        cout << "Neplatne ISBN." << endl;
        return false;
    }

    if(separatorCount==4){
        parseISBN13(separatorCount, isbn);
        return true;
    }

    if(separatorCount==3){
        parseISBN10(separatorCount, isbn);
        return true;
    }

    return true;
}

void kniha::parseISBN13(int count, string kokot) {
    string* varArray[] = {&prefix, &region, &vydavatel, &vydani, &kontrolniCislo};
    size_t pozice;

    for(int i=0; i < count+1; i++){
        pozice = kokot.find("-");
        if(pozice!=string::npos or !kokot.empty()){
            *varArray[i] = kokot.substr(0, pozice);
            kokot.erase(0, pozice+1);
        }
    }

    cout << prefix << endl;
    cout << region << endl;
    cout << vydavatel << endl;
    cout << vydani << endl;
    cout << kontrolniCislo << endl;
}

void kniha::parseISBN10(int count, string kokot) {
    string* varArray[] = {&region, &vydavatel, &vydani, &kontrolniCislo};
    size_t pozice;

    for(int i=0; i < count+1; i++){
        pozice = kokot.find("-");
        if(pozice!=string::npos or !kokot.empty()){
            *varArray[i] = kokot.substr(0, pozice);
            kokot.erase(0, pozice+1);
        }
    }

    cout << region << endl;
    cout << vydavatel << endl;
    cout << vydani << endl;
    cout << kontrolniCislo << endl;
}


void kniha::setDefault() {
    this->title = TITLE;
    this->author = AUTHOR;
    this->isbn = ISBN;
}

string kniha::getTitle() const {
    return this->title;
}

string kniha::getAuthor() const {
    return this->author;
}

string kniha::getISBN() const {
    return this->isbn;
}

void kniha::print() {
    cout << "Title: "<< this->title << endl;
    cout << "Author: "<< this->author << endl;
    cout << "ISBN: " << this->isbn << endl;
}

/*string prefix, region, vydavatel, vydani, kontrolniCislo;
        string* varArray[] = {&prefix, &region, &vydavatel, &vydani, &kontrolniCislo};
        size_t count = std::count_if( isbn.begin(), isbn.end(), []( char c ){return c =='-';});
        size_t pozice;

        for(int i=0; i < count+1; i++){
            pozice = isbn.find("-");
            if(pozice!=string::npos or !isbn.empty()){
                *varArray[i] = isbn.substr(0, pozice);
                isbn.erase(0, pozice+1);
            }
        }

        cout << prefix << endl;
        cout << region << endl;
        cout << vydavatel << endl;
        cout << vydani << endl;
        cout << kontrolniCislo << endl;*/