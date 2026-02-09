#include<iostream>
#include<string>
using namespace std;

int costomaximo(int A[], int n, int pos, int nivel){

    string espacio = string(nivel * 3, ' ');
    cout << espacio << "Entrando: pos = " << pos << endl;

    if(pos == n){

        cout << espacio << "Retornando: 0 (Caso base)" << endl;
        return 0;
    }
    
    int max = -25;
    int producto = 1;

    for(int i = pos; i<n; i++){
        producto *= A[i];

        int costo = producto + costomaximo(A, n, i+1, nivel + 1);

        if(costo > max){

            max = costo;
        }
    }
    
    cout << espacio << "Retornando de pos " << pos << ": " << max << endl;

    return max;

}



int main(){

    int A[10] ;
    int n;

    cout<<"ingrese el tamaño del arreglo: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"ingrese el "<<i+1<<"° elemento: ";
        cin>>A[i];
    }

    int costomax = costomaximo(A, n, 0, 0);

    cout<<"el costo maximo es: "<< costomax;

    return 0;
}