#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void separarpalabras(char** p, char* palabras[], int N){

    int k=0;

    

    for(int i = 0; i<N; i++){

        

    char* token = strtok(*(p+i),",");

    

    while(token != nullptr){

        

        

        palabras[k]=token;

        k++;

        token = strtok(nullptr, ",");

    }

    

    

    }  

}



void clasificar(char** p, char** n, char** d, char** c, int* e, float* t, int N){

    

   for(int i=0; i<N; i++){

       

       int base = i*5;

       

       *(n + i) = *(p + base);      // Nombre

       *(d + i) = *(p + base + 1);  // Dirección

       *(c + i) = *(p + base + 2);  // Celular

       *(e + i) = atoi(*(p + base + 3)); // Edad

       *(t + i) = atof(*(p + base + 4)); // Talla

   }

    

}



int main() {
    char datos_aux[10][100];
    char* datos[10];
    char* palabras[70];
    char* nombres[10];
    char* direccion[10];
    char* celular[10];
    int edad[10];
    float talla[10];
    
    int N_total = 3; // Cuántas queremos pedir
    int N_validos = 0; // Cuántas realmente se guardaron bien

    for(int i = 0; i < N_total; i++) {
        char buffer[100];
        cout << "ingrese los datos de la persona N° " << i + 1 << ": ";
        cin.getline(buffer, 100);

        
        int comas = 0;
        for(int j = 0; buffer[j] != '\0'; j++) {
            if(buffer[j] == ',') comas++;
        }

        if(comas == 4) {
            strcpy(datos_aux[N_validos], buffer);
            datos[N_validos] = datos_aux[N_validos];
            N_validos++;
        } else {
            cout << "Entrada descartada por formato incorrecto." << endl;
        }
    }

    
    if(N_validos > 0) {
        separarpalabras(datos, palabras, N_validos);
        clasificar(palabras, nombres, direccion, celular, edad, talla, N_validos);

        cout << "\nDIRECTORIO FINAL:" << endl;
        for(int i = 0; i < N_validos; i++) {
            cout << *(nombres + i) << " | " << *(direccion + i) << " | " 
                 << *(celular + i) << " | " << *(edad + i) << " | " << *(talla + i) << endl;
        }
    }

    return 0;
}