#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct seleccion{
    string nombre;
    int PG;
    int PE;
    int PP;
    int GF;
    int GC;
    int DG;
    int PT;
    float REND;
};

void asignarvalores(seleccion A[]){

    for(int i=0; i<5; i++){
        A[i].nombre = "Pais "+to_string(i+1);
        A[i].PG = rand()%100 + 1;
        A[i].PP = rand()%(100 - A[i].PG + 1);
        A[i].PE = 100 - A[i].PG - A[i].PP;
    }

    for(int i=0; i<5; i++){

        int golesfavor = 0;
        int golescontra = 0;
        int num = 0;

        for(int i=0; i<A[i].PG; i++){

        golesfavor += rand()%5 + 1;
        golescontra += rand()%(6-golesfavor+1);
        
        }

        for(int i=0; i<A[i].PE; i++){

        num = rand()%5 + 1;

        golesfavor += num;
        golescontra += num;
        }

        for(int i=0; i<A[i].PP; i++){

        golescontra += rand()%5 + 1;
        golesfavor += rand()%(5-golescontra+1);
        
        }

        A[i].GF = golesfavor;
        A[i].GC = golescontra;

        A[i].DG = A[i].GF - A[i].GC;

        A[i].PT = A[i].PG*3 + A[i].PE*1 + A[i].PP*0;

        A[i].REND = (A[i].PT/300.0)*100;

    }


}
void buscarcampeon(seleccion A[]){

    for(int i=0; i<5-1; i++){
        for(int j=0; j<5-i-1; j++){
            if(A[j].PT<A[j+1].PT){
                swap(A[j],A[j+1]);
            }
        }
    }

    
    for(int i=0; i<5; i++){
        cout<<A[i].nombre<<"    "<<A[i].PG<<"    "<<A[i].PE<<"    "<<A[i].PP<<"    "<<A[i].GF<<
        "    "<<A[i].GC<<"    "<<A[i].DG<<"    "<<A[i].PT<<"     "<<A[i].REND<<endl;
    }

    cout<<"CAMPEON: "<<A[0].nombre<<endl;
    cout<<"PUNTAJE: "<<A[0].PT<<endl;
    cout<<"DG: "<<A[0].DG<<endl;
    cout<<"RENDIMIENTO: "<<A[0].REND<<"%"<<endl;

}



int main(){

    srand(time(0));

    seleccion A[5];

    asignarvalores(A);

    cout<<"SELECCION     PG    PE    PP    GF    GC    DG    PT    REND"<<endl;

    buscarcampeon(A);

    


    return 0;
}