#include <iostream>
using namespace std;

//Funcion para imprimir la tabla ASCCI;


void tablaASCCI(){

    for(int i=0; i<128;i++){

        cout<<" A "<< i <<" le corresponde : "<< (char)i <<endl;
    }
}

int main() {
    char c1 = 'A';
    char c2 = 'a';
    char c3 = '0';

    cout << (int)c1 << endl;
    cout << (int)c2 << endl;
    cout << (int)c3 << endl;


    tablaASCCI();
}