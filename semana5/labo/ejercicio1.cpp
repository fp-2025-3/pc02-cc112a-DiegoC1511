#include<iostream>
using namespace std;

struct estudiante{

    char nombre[20];
    int nota;
};

void ordenar(estudiante A[], int n){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(A[j].nota<A[j+1].nota){
                swap(A[j], A[j+1]);
            }
        }

    }



}


int main(){

    int n;
    string espacio(3,' ');

    cout<<"Ingrese el numero de estudiantes: ";
    cin>>n;

    cin.ignore();

    estudiante* A = new estudiante[n];

    for(int i=0; i<n; i++){
        cout<<"Estudiante "<<i+1<<": "<<endl;
        cout<<espacio<<"Nombre: ";
        cin.getline(A[i].nombre,20);
        cout<<espacio<<"Nota: ";
        cin>>A[i].nota;
        cin.ignore();
        cout<<endl;
    }

    ordenar(A, n);

    cout<<"El estudiante con mas nota es: "<<A[0].nombre<<endl;
    cout<<espacio<<"nota: "<<A[0].nota;

    delete[] A;

    return 0;
}