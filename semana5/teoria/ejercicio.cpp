#include<iostream>
#include<cstring>
using namespace std;

/*
a)solicitar al usuario la cantidad de N estudiantes
b)reservar memeoria dinamica para los N estudiantes
c)leer los datos
d)mostrar unicamente aprobados
*/

struct estudiante{

    int codigo;
    float promedio;
    char sexo;
};



int main(){

    string espacio = string(3, ' ');

    int n;

    cout<<"ingrese el numero de estudiantes: "<<endl;
    cin>>n;

    estudiante* A = new estudiante [n];

    for(int i=0; i<n; i++){

        cout<<"Estudiante "<<i+1<<": "<<endl;
        cout<<espacio<<"ingreso codigo: ";
        cin>>A[i].codigo;
        cout<<espacio<<"ingreso promedio: ";
        cin>>A[i].promedio;
        cout<<espacio<<"ingrese su sexo: ";
        cin>>A[i].sexo;
    }

    cout<<"Aprobados: "<<endl;

    for(int i = 0; i < n; i++){
        if(A[i].promedio >= 10){
            cout << "---------------------\n";
            cout << "Codigo: " << A[i].codigo << endl;
            cout << "Promedio: " << A[i].promedio << endl;
            cout << "Sexo: " << A[i].sexo << endl;
            cout << "---------------------\n";
        }
    }


    delete[] A;

    return 0;
}