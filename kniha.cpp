#include <string>
#include "kniha.h"

#define TITLE "The Glass Room"
#define AUTHOR "Simon Mawer"
#define ISBN "978-0-349-12132-1"

kniha::kniha() {
    setDefault();
}

kniha::kniha(string title, string author, string isbn) {
    if(!kontrola(isbn)){
        cout << "Bylo zadano neco spatne, default" << endl;
        setDefault();
    }
    else {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
    }
}

bool kniha::kontrola(string isbn){
    size_t count = std::count_if( isbn.begin(), isbn.end(), []( char c ){return c =='-';});
    cout << "delka isbn: " << isbn.length() << endl;
    cout << "pocet pomlcek: " << count << endl;

    if(isbn.length() < 10 or isbn.length() > 17){ // první kontrola
        return false;
    }

    if(count==0){
        if (isbn.length() == 10){
            string region, vydavatel, vydani, kontrolniCislo;
            string* varArray[] = {&region, &vydavatel, &vydani, &kontrolniCislo};
        }

        else if(isbn.length() == 13){
            string prefix, region, vydavatel, vydani, kontrolniCislo;
            string* varArray[] = {&prefix, &region, &vydavatel, &vydani, &kontrolniCislo};
        }
    }

    return true;
}

void kniha::setDefault() {
    this->title = TITLE;
    this->author = AUTHOR;
    this->isbn = ISBN;
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