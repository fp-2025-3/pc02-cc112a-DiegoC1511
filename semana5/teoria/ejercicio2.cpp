#include<iostream>
using namespace std;
/*
Implementar una agenda de contactos.

Cada contacto tiene nombre y fecha de nacimiento (estructura Fecha)

La cantidad de contactos es desconocida:

a) Reservar memoria dinámica para N contactos

b) Leer datos

c) y mostrar los nacidos en un año específico*/

struct fecha{

    int dias;
    int mes;
    int año;
    
};


struct persona{
    string nombre;
    fecha nacimiento;

};



int main(){
    
    int n;

    cout<<"ingrese el numero de personas: ";
    cin>>n;

    fecha* A = new fecha [n];
    persona* B = new persona [n];
    
    for(int i=0; i<n; i++){
        
    }


    return 0;
}