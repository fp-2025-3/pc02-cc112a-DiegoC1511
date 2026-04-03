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

        for(int j=0; j<A[i].PG; j++){
            int gf = rand()%5 + 1;
            int gc = rand()%gf;

            golesfavor += gf;
            golescontra += gc;
        
        }

        for(int j=0; j<A[i].PE; j++){

            num = rand()%6;

            golesfavor += num;
            golescontra += num;
        }

        for(int j=0; j<A[i].PP; j++){
            int gc = rand()%5 + 1;
            int gf = rand()%gc;

        golescontra += gc;
        golesfavor += gf;
        
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
        cout<<A[i].nombre<<"\t"<<"\t"<<A[i].PG<<"\t"<<A[i].PE<<"\t"<<A[i].PP<<"\t"<<A[i].GF<<
        "\t"<<A[i].GC<<"\t"<<A[i].DG<<"\t"<<A[i].PT<<"\t"<<A[i].REND<<endl;
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

    cout<<"SELECCION       PG      PE      PP      GF      GC      DG      PT      REND"<<endl;

    buscarcampeon(A);

    


    return 0;
}