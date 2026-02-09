#include <iostream>
#include <cstring>
using namespace std;

void ordenartiempos(char* corredores[], int tiempo[], int corr){
    for(int i = 0; i < corr - 1; i++){
        for(int j = 0; j < corr - 1 - i; j++){
            if(*(tiempo + j) > *(tiempo + j + 1)){
                swap(*(tiempo + j), *(tiempo + j + 1));
                swap(*(corredores + j), *(corredores + j + 1));
            }
        }
    }

   
}

void generarranking(char* corredores[], int tiempo[], int corr){
    for(int i = 0; i < corr; i++){
        cout << i + 1 << "° " << *(corredores + i) << " - " << *(tiempo + i) << " segundos" << endl;
    }
}

int buscarcorredor(char* corredores[], char* nombre, int corr){
    
   for(int i=0; i<corr;i++){

    if(strcmp(*(corredores + i), nombre)==0){
        return i + 1;
    }
   }
    return -1;
}


int main(){
    char nombres[30][20];
    char* corredores[30];
    int tiempo[30];
    
    int corr;
    char nombre[30];

    cout << "ingrese el numero de corredores: ";
    cin >> corr;
    cout << endl;

    for(int i = 0; i < corr; i++){
        corredores[i] = nombres[i];
        cout << "nombre del corredor " << i + 1 << ": ";
        cin >> *(corredores + i);
        cout << "tiempo(en segundos): ";
        cin >> *(tiempo + i);
    }

    ordenartiempos(corredores, tiempo, corr);
    generarranking(corredores, tiempo, corr);

    cout << endl;
    cout << "ingrese nombre a buscar: ";
    cin >> nombre;

    int encontro = buscarcorredor(corredores, nombre, corr);

   

    if(encontro != -1){
        cout << "Corredor encontrado" << endl;
        cout << "Posicion: " << encontro<< endl;
        cout << "Tiempo: " << *(tiempo + encontro - 1) << endl;
    }else{
        cout << "no se encontro";   
    }
    
    int min, max;

    cout<<endl;
    cout<<"ingrese minimo y maximo: ";
    cin>>min;
    cin>>max;
    cout<<"corredores en el rango ["<<min<<", "<<max<<"]: ";
    cout<<endl;

    int i=0;

    ordenartiempos(corredores, tiempo, corr);

    while(tiempo[i]<min && i<corr){
        i++;

    }


    while(tiempo[i]>=min && tiempo[i]<=max && i<corr){

        cout<<*(corredores + i)<<" - "<<*(tiempo + i)<<" segundos"<<endl;
        i++;
    }

    return 0;
}
