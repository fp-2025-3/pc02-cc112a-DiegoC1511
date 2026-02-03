#include<iostream>
using namespace std;

void estudiante(int& n){

    cout<<"ingrese el numero de estudiantes: ";
    cin>>n;
}

float* reservarmemoria(int n){

    return new float [n];
}

void leernotas(float* notas, int n){

    for(int i=0; i<n; i++){
        cout<<"ingrese la nota "<<i+1<<": ";
        cin>>*(notas + i);
    }
}

float promedio(float* notas, int n){

    float suma = 0;
    for( int i=0; i<n; i++){
        suma += *(notas + i);
    }
    
    float prom = suma/n;

    return prom;  
    
}

void notamaxmin(float* notas, int n, float &notamax, float &notamin){

    notamax = *(notas + 0);
    notamin = *(notas + 0);

    for(int i = 0; i<n; i++){
        if(*(notas + i) < notamin){
            notamin = *(notas + i);
        }
        if(*(notas + i) > notamax){
            notamax = *(notas + i);
        }
    }
}

void redimensionar(float* &notas, int& n, int k){
    
    float* nuevo = new float[n+k];

    for(int i=0; i<n; i++){
        *(nuevo + i) = *(notas + i);
    }

    delete[]notas;

    notas = nuevo;
    n += k;

}

void liberarmemoria(float* &notas){

    delete []notas;
}

int main(){

    int n;
    float* notas = nullptr;
    float  notamin;
    float  notamax;

    estudiante(n);
    notas = reservarmemoria(n);

    leernotas(notas, n);

    cout<<"promedio inicial: "<<promedio(notas, n);
    cout<<endl;

    notamaxmin(notas, n, notamax, notamin);
    int k;
    cout<<"ingrese la cantidad de estudiantes  agregar: ";
    cin>>k;

    redimensionar(notas, n, k);

    leernotas(notas, n);

    cout<<"nuevo promedio: "<<promedio(notas, n);
    cout<<endl;

    notamaxmin(notas, n, notamax, notamin);

    cout<<"la nota maxima es: "<<notamax;
    cout<<endl;
    cout<<"la nota minima es: "<<notamin;

    liberarmemoria(notas);




    return 0;
}