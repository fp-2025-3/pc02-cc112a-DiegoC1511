#include <iostream>
using namespace std;

int main(){

char c = 'A';
c = c + 1;
cout << c;
// 'A'  = 65
// 65 + 1 = 66 --> 'B'

cout<<endl;

char ch = 'z';

ch = ch + 1;

cout<<ch<<endl; //imprime el caracter que le sigue a z en la table ASCCI

// 'z' + 1 ?

char c1 = 'D';
c1 = c1 + ('a' - 'A');

//'a' - 'A' = 32

char c2 = 'G';
c2 = c2 + ('a' - 'A');

cout<<c2<<endl;
cout<<c1<<endl;


return 0;
}