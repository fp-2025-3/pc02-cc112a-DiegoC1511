#include<iostream>
#include<cstring>
using namespace std;

/*1.1. Leer una frase de longitud desconocida.

1.2. Almacenar la frase usando asignación dinámica exacta (ni más ni menos memoria).

1.3. Normalizar la frase:

- Eliminar espacios múltiples.

- Convertir todas las letras a minúsculas
1.4. Contar cuántas palabras tiene la frase.

1.5. Construir dinámicamente un arreglo de palabras, donde cada palabra es un char* independiente.

1.6. Mostrar cada palabra junto con su longitud.

1.7. Liberar toda la memoria dinámica correctamente. */

char* leerfrase(){

    char temp[1000];

    cout<<"Ingrese el texo: ";
    cin.getline(temp, 1000);

    int len = strlen(temp);

    char* frase = new char[len + 1];
    strcpy(frase, temp);

    return frase;

}

char* normalizar(char* frase){

    int n = strlen(frase);
    char* aux = new char [n +1];  
    
    int j=0;
    bool espacio = true;

    for(int i=0; i<n; i++){

        char c = *(frase + i);

        if(c>='A' && c<='Z'){

            c = c + 32;
        }

        if(c != ' '){

            *(aux + j) = c;
            j++;
            espacio = false;
        }else if(espacio == false){
            *(aux + j) = ' ';
            j++;
            espacio = true;
        }

        
        
    }
    
    if(j>0 && *(aux + j-1)==' '){
            j--;
            
    }

    *(aux + j) = '\0';

    char* normalizada = new char [j+1];
    strcpy(normalizada, aux);

    delete[]frase;
    delete[]aux;

    return normalizada;

}

int contarpalabras(char* normalizada){

    int contador = 0;

    while(*normalizada!='\0'){
        if(*normalizada == ' '){
            contador++;
        }
        normalizada ++;
    }


   return contador + 1;
}

char** segmentar(char* normalizada, int numpalabras){
    
    char**lista = new char* [numpalabras];

    char* token = strtok(normalizada, ", ");
    
    int i=0;

    while (token != nullptr) {

        int tampal = strlen(token);
        *(lista + i) = new char [tampal+ 1 ];
        strcpy(*(lista + i), token);
        token = strtok(nullptr, ", "); // continua analizando la cadena 

        i++;
    }
    

    return lista;
}

void mostrar(char**lista, int numpal){

    for(int i=0; i<numpal; i++){
        cout<<*(lista + i )<<" "<<strlen(*(lista + i ))<<endl;
    }
}

void liberarmemo (char** lista, int numpal, char* frasenormada){
    
    for(int i=0; i<numpal; i++){

        delete[]lista[i];
    }
    delete[]lista;
    delete[]frasenormada;

}



int main(){

   char* frase = leerfrase();

   char* frasenormada = normalizar(frase);

   int numpal = contarpalabras(frasenormada);

   char** listadepal = segmentar(frasenormada, numpal);

   mostrar(listadepal, numpal);

   cout<<endl;


   liberarmemo(listadepal, numpal,frasenormada);



    return 0;
}