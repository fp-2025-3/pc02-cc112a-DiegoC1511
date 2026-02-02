#include <iostream>
#include <cstring>
using namespace std;

int convertir(char* p) {
    int num = 0;

    while (*p != '\0') {
        num = num * 10 + (*p - '0');
        p++;
    }
    return num;
}

int separarnumeros(char* texto, int numeros[]) {
    int m = 0;
    char* token = strtok(texto, ", ");

    while (token != nullptr) {
        numeros[m++] = convertir(token);
        token = strtok(nullptr, ", ");
    }
    return m;
}

bool buscarsuma(int numeros[], int m, int k) {
    int i = 0, j = m - 1;

    while (i < j) {
        int suma = numeros[i] + numeros[j];

        if (suma == k)
            return true;
        else if (suma < k)
            i++;
        else
            j--;
    }
    return false;
}

int main() {
    char texto[100];
    int numeros[20];
    int k;

    cout << "Ingrese el texto: ";
    cin.getline(texto, 100);

    cout << "Ingrese la suma a buscar: ";
    cin >> k;

    int m = separarnumeros(texto, numeros);

    if (buscarsuma(numeros, m, k))
        cout << "Si existen 2 numeros con suma " << k;
    else
        cout << "No existen 2 numeros con suma " << k;

    return 0;
}