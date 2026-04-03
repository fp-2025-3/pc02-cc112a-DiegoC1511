#include<iostream>
using namespace std;

void agregarestudiante(int* &codigos, float* &promedios, int&tam, int &cap, int codigo, float promedio){

    if(tam==cap){
        cap = cap*2;

        int* nuevocodigo = new int [cap];
        float* nuevoprom = new float[cap];

        for(int i=0; i<tam; i++){
            *(nuevocodigo  + i) = *(codigos + i);
            *(nuevoprom + i)= *(promedios + i);
        }

        delete[] codigos;
        delete[] promedios;

        codigos=nuevocodigo;
        promedios=nuevoprom;
    }

    codigos[tam] = codigo;
    promedios[tam]= promedio;
    tam++;

}

void filtraryredimensionar(int* &codigos, float* &promedios, int& tam, int&cap){
    int contaraprobados = 0;

    for(int i=0; i<tam; i++){
        if(*(promedios + i)>=10){
            contaraprobados++;
        }
    }

    int* nuevocod = new int[contaraprobados];
    float* nuevoprom = new float[contaraprobados];

    int j=0;    

    for(int i=0; i<tam; i++){
        if(*(promedios+i)>=10){
            *(nuevocod + j) = *(codigos + i);
            *(nuevoprom + j) = *(promedios + i);
            j++;
        }
    }

    delete[] codigos;
    delete[] promedios;
    codigos = nuevocod;
    promedios = nuevoprom;

    tam=contaraprobados;
    cap=contaraprobados;
}

void mostaralumnos(int* codigos, float* promedios, int tam){

    for(int i=0; i<tam; i++){
        cout<<"codigos: "<<*(codigos + i)<<" promedio: "<<*(promedios+ i)<<endl;
    }
}

int main(){

    int cap = 2;
    int tam = 0;
    int* codigos = new int[cap];
    float* promedios = new float[cap];

    agregarestudiante(codigos, promedios, tam, cap, 101, 14.5);
    agregarestudiante(codigos, promedios, tam, cap, 102, 8.0);
    agregarestudiante(codigos, promedios, tam, cap, 103, 16.2);
    agregarestudiante(codigos, promedios, tam, cap, 104, 9.5);
    agregarestudiante(codigos, promedios, tam, cap, 105, 12.30);

    cout<<"MOSTRAR ESTUDIANTES REGISTRADOS: "<<endl;
    mostaralumnos(codigos, promedios, tam);
    cout<<endl;
    cout<<"FILTRANDO ESTUDIANTES..."<<endl;
    cout<<endl;
    filtraryredimensionar(codigos, promedios, tam, cap);
    cout<<"ESTUDIANTES APROBADOS: "<<endl;
    mostaralumnos(codigos, promedios, tam);
    cout<<endl;


    delete[] codigos;
    delete[] promedios;


    return 0;
}
