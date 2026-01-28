#include <iostream>
using namespace std;

// Construye el índice de punteros a palabras
int construir_indice(char* texto, char* indice[]) {

    
    int n = 0;
    char* p = texto;

    while (*p != '\0') {
        
        while (*p == ' '){
           p++;
        }

        if (*p == '\0'){ 
        break;
        }
        
        indice[n++] = p;

       
        while (*p != ' ' && *p != '\0'){
             p++;
        }
    }    

    return n;
}


int comparar(const char* a, const char* b) {
    while(*a != '\0' && *b != '\0' ){

        if(*a != *b){
            return *a - *b;
            
        }
        a++;
        b++;
    }

    return *a - *b;
}

// Ordena el índice alfabéticamente usando burbuja
void ordenar_indice(char* indice[], int n) {
    for( int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(comparar(*(indice + j),*(indice+j+1))>0){
                swap(*(indice +j),*(indice +j+1));
            }

        }
    }
}


void imprimir_indice(char* texto, char* indice[], int n) {
    for (int i = 0; i < n; i++) {
        char* p = indice[i];
        
        while (*p != ' ' && *p != '\0') {
            cout << *p;
            p++;
        }
        cout << " (posicion " << (indice[i] - texto) << ")" << endl;
    }
}

int main() {
    char texto[300] = "los punteros no se copian se referencian y se ordenan";
    char* indice[60];

    int n = construir_indice(texto, indice);
    ordenar_indice(indice, n);
    imprimir_indice(texto, indice, n);

    cout<<texto;

    return 0;
}
