#include<iostream>
using namespace std;

int separar_palabras(char* frase, char* palabras[]){

    int cont = 0;
    
    while(*frase != '\0'){

          *(palabras + cont) = frase;
          cont++;
          
          while(*frase != ' ' && *frase != '\0'){

            frase++;
          }

          if(*frase == ' '){
            *frase = '\0';
            frase++;

          }

    }
    return cont;    


}

int comparar(const char* a, const char* b){

     while(*a != '\0' && *b != '\0' ){

        if(*a != *b){
            return *a - *b;
            
        }
        a++;
        b++;
    }

    return *a - *b;
 
}

void ordenar(char* palabras[], int n){

    for( int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(comparar(*(palabras + j),*(palabras+j+1))>0){
                swap(*(palabras+j),*(palabras+j+1));
            }

        }
    }

}

void imprimir(char* palabras[], int n){

    for(int i=0; i<n; i++){

        cout<<palabras[i]<<endl;

    }
}

int main(){

    char frase[200] = "aprender    punteros exige mucha logica y practica";      // arreglo base de caracteres
    char* palabras[50];
    int cant_pal;


    cant_pal = separar_palabras(frase, palabras);

    ordenar(palabras, cant_pal);

    imprimir(palabras, cant_pal);
    
    cout<< frase;



}


