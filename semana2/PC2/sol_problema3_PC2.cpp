#include <iostream>
using namespace std;

const int columnas = 5;  

bool numeropico( int (*M)[columnas], int filas, int columnas, int i, int j){
    
    int act = *(*(M + i) + j);
    
    bool mayorigual = true;
    bool mayorestric= false;
    
    //comparar con los elementos de arriba
    
    if(i - 1 >= 0){
        int nuevo = *(*(M + i - 1) + j);
        
        if(act < nuevo){            // si no se cumple que act < nuevo
            mayorigual = false;     // entonces por logica act >= nuevo y
        }                           // mayorigual seguira siendo true
        if(act > nuevo){
            mayorestric = true;     // se verifica el mayor estricto
        }
        
    }
    
    // comparar con los elementos de la abajo
    
    if(i + 1 < filas){
        int nuevo = *(*(M + i + 1) + j);
                                    
        if(act < nuevo){             // si no se cumple que act < nuevo
            mayorigual = false;      // entonces por logica act >= nuevo y
        }                            // mayorigual seguira siendo true
        if(act > nuevo){
            mayorestric = true;      // se verifica el mayor estricto
        }
        
    }
    
    //comparar con los elementos de la izquierda
    
    if(j - 1 >= 0){
        int nuevo = *(*(M + i ) + j - 1);
        
        if(act < nuevo){             // si no se cumple que act < nuevo
            mayorigual = false;      // entonces por logica act >= nuevo y
        }                            // mayorigual seguira siendo true
        if(act > nuevo){
            mayorestric = true;      // se verifica el mayor estricto
        }
        
    }
    
    //comparar con los elementos de la derecha
    
    if(j + 1 < columnas){
        int nuevo = *(*(M + i ) + j + 1);
        
        if(act < nuevo){
            mayorigual = false;
        }
        if(act > nuevo){
            mayorestric = true;
        }
        
    }
    
    
    
    return mayorestric && mayorigual;  //retorna true si ambos son true
}

void imprimir( int (*M)[columnas], int filas, int columnas){
    
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            if(numeropico(M, filas, columnas, i, j) == true){
                
                cout<<"pico en ("<<i<<","<<j<<"): "<<*(*(M + i) + j)<<endl;
            }
        }
    }
    
}


int main(){
    
    const int filas = 4;
    const int columnas = 5;
    
    int M[filas][columnas] = {{3,3,3,3,3},{3,4,4,2,3},{3,4,5,4,3},{3,3,3,3,3}};
    cout<<"elementos pico: "<<endl;
    imprimir(M, filas, columnas);
    
    
    

    return 0;
}