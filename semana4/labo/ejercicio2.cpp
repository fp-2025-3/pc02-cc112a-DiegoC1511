#include<iostream>
using namespace std;

const int N = 5;

bool filadomiante( int (*M)[N], int fila){

    bool dominante = true;

    

    for( int i=0; i<N && dominante==true; i++){
        for(int j=0; j<N; j++){

            if(j==fila){
                continue;
            }

            if(*(*(M + fila) + i)<=(*(*(M + j) + i)) ){

                dominante = false;

            } 
        }
        
    }

    return dominante;


}

int contarColumnasCriticas(int (*M)[N]){

    int sumas[N];
    int sumamax = 0;
    int cont =0;
    
    for(int i=0; i<N; i++){
        
        int sumafil=0;

        for(int j=0; j<N; j++){

            sumafil += *(*(M + i) + j) ;

        }
        *(sumas + i) = sumafil;

        if(sumafil>sumamax){

            sumamax=sumafil;
        }
       
     
    }

    for(int i=0; i<N; i++){
        int sumacol=0;

        for(int j=0; j<N; j++){

            sumacol += *(*(M + j)+i);
        }
        
        if(sumacol>sumamax){
            cont++;
        }
    }

    return cont;
}

bool matrizescalonada(int (*M)[N]){

    int colant=-1;

    for(int i=0; i<N; i++){
        int colactu=-1;

        for(int j=0; j<N; j++){

            if(*(*(M + i)+j)!=0){
                colactu=j;
                break;

            }
        }

        if(colactu == -1){

            for(int k=i+1; k<N;k++){
                for(int j=0;j<N; j++){
                    if(*(*(M +k)+j)!=0){
                        return false;
                    }
                }
            }
            return true;
        }
        if(colactu<=colant){
            return false;
        }

        colant=colactu;
    }

    return true;
}

int nucleo(int (*M)[N], int fila, int columna){

    bool maximofila = true;
    bool minimocolum = true;

    for(int i=0; i<N; i++){
       
             
         if(*(*(M + fila) + columna) < *(*(M + fila )+ i)){

            maximofila = false;
                
        }

        if(*(*(M + fila) + columna) > *(*(M + i) + columna)){

            minimocolum = false;
        }

        
    }
    if(maximofila && minimocolum){
        return *(*(M+fila)+columna);
    }else{
        return -1;
    }
}


int main(){

    int M[N][N] = {
    {10, 10, 10, 10, 10}, // Fila 0: DOMINANTE (todos son los más grandes)
    {1, 2, 3, 4, 5},
    {0, 0, 0, 0, 0},
    {5, 4, 3, 2, 1},
    {1, 1, 1, 1, 1} };
    int colcri;

    for( int i=0; i<N; i++){
       
        if( filadomiante(M, i)){
            cout<<"la fila "<<i+1<<" es dominante. "<<endl;
        
    }

    colcri = contarColumnasCriticas(M);

    cout<<"hay "<<colcri<<" columnas criticas"<<endl;

    if(matrizescalonada(M)){
        cout<<"es matriz escalonada. "<<endl;
    }else{
        cout<<"no es matriz escalonada."<<endl;
    }

    for( int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            if(nucleo(M, i, j) != -1){
              cout<<"un nucleo es: "<<nucleo(M, i, j)<<" ubicado en ("<<i+1<<", "<<j+1<<")"<<endl;
            }

            
        }
        
    }


    


    
    





    return 0;
}
}

