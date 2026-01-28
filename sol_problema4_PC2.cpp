#include <iostream>
using namespace std;

int sumasubmatriz(int (*M)[5], int filas, int i1, int j1, int i2, int j2){
    
    int suma=0;                       //(i1, j1) y (i2, j2) son los 
                                      // extremos la submatriz 
    for(int i=i1; i<=i2; i++){
        for(int j=j1; j<=j2; j++){
            suma += *(*(M+i)+ j);
            
        }
    }
    
    return suma;
}

void submatrizmax(int (*M)[5], int filas, int columnas){
    
    int sumamax = *(*(M + 0) + 0); 
    int bi1=0, bi2=0, bj1=0, bj2=0;          //(bi1,bj1) y (bi2, bj2) son los
                                             //extremos de la nueva submatriz
    for(int i=0; i<filas; i++){              
        for(int j=0; j<columnas; j++){
            
            for(int k=i; k<filas; k++){
                for(int l=j; l<columnas; l++){
                    
                    int sumaact = sumasubmatriz(M,filas, i, j, k, l);
                    
                    if(sumaact > sumamax){
                        
                        sumamax = sumaact;
                        
                        bi1 = i;
                        bj1 = j;
                        bi2 = k;
                        bj2 = l;
                    }
                }
            }
        }
    }
    
    cout<<"Esquina superior izquierda: ("<<bi1<<", "<<bj1<<")"<<endl;
    cout<<"Esquina inferior derecha: ("<<bi2<<", "<<bj2<<")"<<endl;
    cout<<"suma maxima: "<<sumamax<<endl;
    
}

int main(){
    
  int M[4][5] = { { -2,  1, -3,  4, -1 },
                  {  2,  3, -2,  1, -5 },
                  { -1,  4,  2, -3,  2 },
                  {  1, -2,  3,  4, -1 }};
                  
  int filas = 4;
  int columnas = 5;
  
  submatrizmax(M, filas, columnas);

    return 0;
}