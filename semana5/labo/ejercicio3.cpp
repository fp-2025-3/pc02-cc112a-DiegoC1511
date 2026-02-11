#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct equipos{

    char nombre[20];
    int num;
    int pg;
    int pe;
    int pp;
    int puntaje;
    double rendimiento;

};


void asignarpuntajes(equipos A[]){

    for(int i=0; i<5; i++){
        
        A[i].num = i+1;
        A[i].pg = rand()% 100 + 1;
        A[i].pe = rand()% (100 - A[i].pg + 1);
        A[i].pp = 100 - A[i].pg - A[i].pe; 
        A[i].puntaje = A[i].pg*3 + A[i].pe*1 + A[i].pp*0;
        A[i].rendimiento = (A[i].puntaje/300.0)*100;
    }

}

void buscar(equipos A[]){

    for(int i=0; i<5-1; i++){
        for(int j=0; j<5-1-i; j++){
            if(A[j].puntaje<A[j+1].puntaje){
                swap(A[j], A[j+1]);
            }
        }

    }
}

int main(){

    srand(time(0));

    equipos A[5];

    asignarpuntajes(A);

    cout<<"Seleccion            PG      PE      PP      PUNTAJE      RENDIMIENTO"<<endl;
    for(int i=0; i<5; i++){
        cout<<"Pais_seleccion "<<i+1<<"     "<<A[i].pg<<"      "<<A[i].pe<<"      "<<A[i].pp<<"      "<<A[i].puntaje<<"      "<<A[i].rendimiento<<endl;
    }

    buscar(A);

    cout<<"El equipo con mayor puntaje es: "<<A[0].num<<" con "<<A[0].puntaje;




    return 0;
}