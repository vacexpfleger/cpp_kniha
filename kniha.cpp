#include <string>
#include "kniha.h"

#define TITLE "The Glass Room"
#define AUTHOR "Simon Mawer"
#define ISBN "978-0-349-12132-1"

#define MIN_LENGTH 3
#define MAX_LENGTH 100

kniha::kniha() {
    setDefault();
}

kniha::kniha(const string& title, const string& author, const string& isbn) {
    if(!kontrola(title, author, isbn)){
        setDefault();
    }
    else {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
        setKniha(title, author, isbn);
    }
}

kniha::kniha(const kniha &copy) {
    this->title = copy.title;
    this->author = copy.author;
    this->isbn = copy.isbn;
}

bool kniha::kontrola(const string& newTitle, const string& newAuthor, const string& newIsbn){
    size_t separatorCount = count_if(newIsbn.begin(), newIsbn.end(), []( char c ){return c =='-';});
    int length = newIsbn.length();

    if(newTitle.length() < MIN_LENGTH or newTitle.length() > MAX_LENGTH){
        cout << "Neplatny nazev knihy." << endl;
        return false;
    }

    if(newAuthor.length() < MIN_LENGTH or newAuthor.length() > MAX_LENGTH){
        cout << "Neplatne jmeno autora." << endl;
        return false;
    }

    if(length < 10 or length > 17) {
        cout << "Neplatne ISBN." << endl;
        return false;
    }

    if(separatorCount==4){
        if(!validateIsbn13(parseISBN13(separatorCount, newIsbn))){
            cout << "Neplatne ISBN." << endl;
            return false;
        }
        else {
            return true;
        }
    }

    else if(separatorCount==3){
        if(!validateIsbn10(parseISBN10(separatorCount, newIsbn))){
            cout << "Neplatne ISBN." << endl;
            return false;
        }
        else {
            return true;
        }
    }

    else if(separatorCount==0) {
        vystup = " || Delka: " + to_string(length);
        return true;
    }
}

string kniha::parseISBN13(int count, string newIsbn) {
    string* varArray[] = {&prefix, &region, &vydavatel, &vydani, &kontrolniCislo};
    size_t pozice;

    for(int i=0; i < count+1; i++){
        pozice = newIsbn.find("-");
        if(pozice!=string::npos or !newIsbn.empty()){
            *varArray[i] = newIsbn.substr(0, pozice);
            newIsbn.erase(0, pozice+1);
        }
    }

    vystup = " || Prefix: " + prefix + " Region: " + region + " Vydavatel: " + vydavatel + " Vydani: " + vydani;
    cout << vystup << endl;
    return prefix + region + vydavatel + vydani + kontrolniCislo;
}

string kniha::parseISBN10(int count, string newIsbn) {
    string* varArray[] = {&region, &vydavatel, &vydani, &kontrolniCislo};
    size_t pozice;

    for(int i=0; i < count+1; i++){
        pozice = newIsbn.find("-");
        if(pozice!=string::npos or !newIsbn.empty()){
            *varArray[i] = newIsbn.substr(0, pozice);
            newIsbn.erase(0, pozice+1);
        }
    }

    vystup = " || Region: " + region + " Vydavatel: " + vydavatel + " Vydani: " + vydani;
    return region + vydavatel + vydani + kontrolniCislo;
}

bool kniha::validateIsbn10(string newIsbn){
    int n = newIsbn.length();
    if (n != 10)
        return false;
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int value = newIsbn[i] - '0';
        if (0 > value || 9 < value)
            return false;
        sum += (value * (10 - i));
    }
    char last_val = newIsbn[9];
    if (last_val != 'X' && (last_val < '0' || last_val > '9'))
        return false;
    sum += ((last_val == 'X') ? 10 : (last_val - '0'));
    return (sum % 11 == 0);
}

bool kniha::validateIsbn13(string newIsbn){
    int sum = 0;
    for (int i = 1; i <= 13; i++) {
        int digit = newIsbn[i - 1] - '0';
        sum += (digit * (i % 2 ? 1 : 3));
    }
    if (sum % 10 != 0) {
        return false;
    }
    else {
        return true;
    }
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

void kniha::setKniha(const string& newTitle, const string& newAuthor, const string& newIsbn) {
    this->title = newTitle;
    this->author = newAuthor;
    this->isbn = newIsbn;
}

kniha& kniha::operator=(const kniha &copy){
    this->title = copy.isbn;
    this->author = copy.author;
    this->isbn = copy.isbn;
}

bool kniha::operator==(const kniha &second){
    if(this->title==second.title and this->author==second.author and this->isbn==second.isbn){
        return true;
    }
    else {
        return false;
    }
}

std::ostream & operator<<(std::ostream& os, const kniha& book){
    os << "ISBN: " << book.getISBN() << book.vystup << "\nAutor: " << book.getAuthor()
    << "\nNazev: " << book.getTitle() << endl << "\n";
    return os;
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