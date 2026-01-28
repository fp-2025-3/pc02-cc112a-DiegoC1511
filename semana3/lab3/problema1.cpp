#include<iostream>
using namespace std;


int separar_palabras(char* texto, char* palabras[]){

    int contador = 0;


    while(*texto != '\0'){

        
        palabras[contador] = texto;
        contador++;

        //hola mundo

        while(*texto != ' ' && *texto != '\0'){
        
         texto++;

        }

        if(*texto == ' '){
            *texto = '\0';
             texto++;
        }
    } 
    
    return contador;

}

int longitud_palabra(const char* p){
    
    int cont = 0;
    while( *p != '\0'){
        p++;
        cont++;
    }
    
    return cont;
}

void clasificar(char* palabras[], int n,
                char* cortas[], int& nc,
                char* largas[], int& nl){

for(int i=0; i<n; i++){

    if(longitud_palabra(*(palabras + i))>3){

        *(largas + nl) = *(palabras + i);
        nl++;
    }else {
        *(cortas + nc ) = *(palabras + i);
        nc++;
    }
}
                           
}

int comparar_palabras(const char* a, const char* b){
    
    while(*a != '\0' && *b != '\0' ){

        if(*a != *b){
            return *a - *b;
            
        }
        a++;
        b++;
    }

    return *a - *b;

}

void ordenar(char* v[], int n){

    for(int i = 0; i< n - 1; i++){

        for(int j = 0; j< n-1-i; j++){

            if(comparar_palabras(*(v + j), *(v+j + 1))>0){

                char* temp = *( v + j );
                *(v+j) = *(v+j+1);
                *(v+j+1) = temp;

            }
        }
    }
}

void imprimir_grupo(const char* titulo, char* v[], int n){

    cout<<titulo<<endl;

    for(int i=0; i<n; i++){
        cout<<*(v + i)<<endl;

    }
}


int main(){
     
    char texto[300] = "Programar en C++ requiere logica C++ exige disciplina";
    char* palabras[60];
    char* cortas[60];
    char* largas[60];
    int cant_palabra;
    int nc = 0;
    int nl = 0;

    cant_palabra = separar_palabras(texto, palabras);
    clasificar(palabras, cant_palabra, cortas, nc, largas, nl);
    ordenar(cortas, nc);
    ordenar(largas, nl);

    imprimir_grupo("Plabras cortas: ", cortas, nc);
    imprimir_grupo("Palabras largas: ", largas, nl);

    cout<<endl;
    cout<<texto;
     
    
    return 0;
}



