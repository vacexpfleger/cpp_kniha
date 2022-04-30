#include <iostream>
#include <string>
#include "kniha.h"

using namespace std;

int main() {
    bool run = true;

    cout << "Objekt k1 vytvoreny vychozim konstruktorem" << endl;
    cout << "------------------------------------------" << endl;
    kniha k1;
    cout << k1;

    cout << "\nObjekt k2 vytvoreny kopirovacim konstruktorem" << endl;
    cout << "------------------------------------------" << endl;
    kniha k2(k1);
    cout << k2;

    while(run){
        string t, a, i;
        cout << "Zadej titul knihy: ";
        cin >> t;
        cout << "Zadej autora knihy: ";
        cin >> a;
        cout << "Zadej ISBN knihy: ";
        cin >> i;

        kniha k3(t, a, i);
        cout << "\nObjekt k3 vytvoreny konstruktorem s parametry" << endl;
        cout << "------------------------------------------" << endl;
        cout << k3;

        if(!(k2==k3)){
            cout << "Objekt k2 a k3 nejsou stejne." << endl;
        }

        bool loop = true;
        while(loop){
            char choice;
            cout << "Chcete pokracovat (y/n)? ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y'){
                loop = false;
            }
            else{
                loop = false;
                run = false;
            }
        }
    }
   /* string t, a, i;

    cout << "Objekt k1 vytvoreny vychozim konstruktorem" << endl;
    cout << "------------------------------------------" << endl;
    kniha k1;
    cout << k1;

    cout << "\nObjekt k2 vytvoreny kopirovacim konstruktorem" << endl;
    cout << "------------------------------------------" << endl;
    kniha k2(k1);
    cout << k2;

    cout << "Zadej titul knihy: ";
    cin >> t;
    cout << "Zadej autora knihy: ";
    cin >> a;
    cout << "Zadej ISBN knihy: ";
    cin >> i;

    if(t,a,i == "\n"){
        return 1;
    }

    kniha k3(t, a, i);
    cout << "\nObjekt k3 vytvoreny konstruktorem s parametry" << endl;
    cout << "------------------------------------------" << endl;
    cout << k3;

    if(!(k2==k3)){
        cout << "Objekt k2 a k3 nejsou stejne.";
    }
*/
    return 0;
}
