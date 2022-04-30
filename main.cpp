#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "kniha.h"

using namespace std;

int main() {
    string t;
    string a;
    string i;

    kniha k1;
    cout << k1.getTitle() << endl;

    cout << "Zadej titul knihy: ";
    cin >> t;
    cout << "Zadej autora knihy: ";
    cin >> a;
    cout << "Zadej ISBN knihy: ";
    cin >> i;

    kniha k2(t, a, i);
    k2.print();

/*    string isbn, prefix, region, vydavatel, vydani;
    string* varArray[] = {&prefix, &region, &vydavatel, &vydani};
    size_t pozice;

    cout << "Zadej ISBN: ";
    cin >> isbn;

    size_t count = std::count_if( isbn.begin(), isbn.end(), []( char c ){return c =='-';});

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
    cout << vydani << endl;*/

    return 0;
}
