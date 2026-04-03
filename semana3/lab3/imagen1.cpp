#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int N = 9;


void permutar(int* fila){
    
    for(int i=0; i<N; i++){
        
        *(fila + i) = i + 1; //1 2 3 4 5 6 7 8 9
        
    }
    
    for(int i=N - 1; i>0; i--){
        
        int j = rand()%(i + 1);
        
        int temp = *(fila + i);
        *(fila + i) = *(fila +j);
        *(fila + j) = temp;
        
    }
    
}

void imprimir(int **M){
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            cout<<*(*(M + i) + j)<<" ";
            
            
        }
        cout<<endl;
    }
}

void desplazarfila(int* fila, int desplazar){
    
    int aux[N];
    
    for(int j=0; j<N ; j++){
        
        int nuevapos = (j + desplazar) % N;
        
        if(nuevapos < 0){
            
        nuevapos = nuevapos + N;
        
        }
        
        aux[nuevapos] = *(fila + j);
    }
    
    for(int i=0; i<N; i++){
        
        *(fila + i) = aux[i];
        
        
    }
    
    
}

int main(){
    
    srand(time(0));
    
    int M[N][N];
    int* filas[N];
    
    for(int i=0; i<N; i++){
        
        filas[i] = M[i];
    }
    
    
    for(int i=0; i<N; i++){
        
        permutar(*(filas +i));
        
    }
    
    cout<<"Matriz incial: "<<endl;
    
    imprimir(filas);
    
    int I,J;
    
    cout<<"fila incial: ";
    cin>>I;
    cout<<"columna incial: ";
    cin>>J;
    
    I--;
    J--;
    
    int valor = *(*(filas + I) + J );
    
    cout<< "valor seleccionado: "<< valor;
    
    for( int i=0; i<N; i++){
        
        int pos =0;
        
        while( *(*(filas + i) + pos) != valor){
            
            pos++;
        }
        

        
        int desplazamiento = J - pos;
        
        desplazarfila(*(filas + i), desplazamiento);
    }
    
    
    cout<<"tablero final";
    
    imprimir(filas);

    return 0;
}