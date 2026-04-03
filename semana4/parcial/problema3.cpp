#include<iostream>
using namespace std;

const int N = 4;

bool filadominanteestrica(int (*M)[N], int f) {
   
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (f == i){
               continue;
            }
            
            
            if (*(*(M + f) + j) < *(*(M + i) + j)) {
                return false; 
            }
        }
    }

    
    bool existeColumnaEstricta = false;
    
    for (int j = 0; j < N; j++) {
        bool esMayorQueTodosEnEstaCol = true;
        
        for (int i = 0; i < N; i++) {
            if (f == i) continue;
            
            
            if (*(*(M + f) + j) <= *(*(M + i) + j)) {
                esMayorQueTodosEnEstaCol = false;
                break;
            }
        }
        
       
        if (esMayorQueTodosEnEstaCol) {
            existeColumnaEstricta = true;
            break; 
        }
    }

    return existeColumnaEstricta;
}

bool fuertementedominante(int (*M)[N], int f) {
   
    if (filadominanteestrica(M, f) == false) {
        return false;
    }

   
    int sumaFilaF = 0;
    for (int j = 0; j < N; j++) {
        sumaFilaF += *(*(M + f) + j);
    }

    
    for (int i = 0; i < N; i++) {
        if (i == f) continue;

        int sumaOtra = 0;
        for (int j = 0; j < N; j++) {
            sumaOtra += *(*(M + i) + j);
        }

        
        if (sumaFilaF <= sumaOtra) {
            return false; 
        }
    }

    return true;
}



int main(){

    int M[N][N]={{2,3,1,4},{1,2,3,2},{5,6,7,8},{0,1,2,1}};

    

    cout<<"FILA   DOMINANTE FILA   FUERTEMENTE DOMINANTE"<<endl;

    for(int i=0; i<N;i++){

        cout<<i<<"            ";

         if(filadominanteestrica(M, i)==true){
            cout<<"si"<<"            ";
         }
         else{
            cout<<"no"<<"            ";
         }

        if(fuertementedominante(M, i)==true){
            cout<<"si"<<"            ";
         }else{
            cout<<"no"<<"            ";
        }

        cout<<endl;


    }

    return 0;
}