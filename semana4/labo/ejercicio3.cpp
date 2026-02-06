#include<iostream>
using namespace std;

void ordenarpornotas(int codigo[], float notas[], int faltas[], int n){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(notas[j]<notas[j+1] ||(notas[j]==notas[j+1] && faltas[j]>faltas[j+1])){

                swap(notas[j],notas[j+1]);
                swap(codigo[j], codigo[j+1]);
                swap(faltas[j], faltas[j+1]);
            }

        }

    }
}

void ordenarporcodigo(int codigo[], float notas[], int faltas[], int n){

    for(int i=0; i<n-1; i++){

        int min_idx = i;
        for(int j=i+1; j<n;j++){
            if(codigo[j]<codigo[j+1]){
                min_idx = j;
            }
        }

        swap(codigo[i], codigo[min_idx]);
        swap(notas[i], notas[min_idx]);
        swap(faltas[i], faltas[min_idx]);
    }

}

int busquedabinaria(int codigo[], int n, int clave){

    int inicio = 0;
    int final = n-1;
    while(inicio<=final){
        int medio = (inicio +final)/2;
        if(codigo[medio]==clave){
            return medio;
        }else if(codigo[medio]<clave){
            inicio = medio + 1;
        }else{
            final = medio -1;
        }
    }

    return -1;
}

int contardesaprobado(float notas[], int n){
    int cont =0;
    for(int i=0; i<n; i++){
        if(notas[i]<10){
            cont++;
        }
    }

    return cont;
}

int main(){

    int codigo[20];
    float notas[20];
    int faltas[20];
    int alum;
    float prom;
    int clave;

    cout<<"ingrese la cantidad de alumnos: ";
    cin>>alum;

    for(int i = 0; i<alum; i++){
        cout<<" ingrese el codigo: ";
        cin>>codigo[i];
        cout<<"ingrese su nota: ";
        cin>>notas[i];
        cout<<"ingrese sus faltas: ";
        cin>>faltas[i];

    }
    ordenarpornotas(codigo, notas, faltas ,alum);

    cout<<"El ranking de los 5 menores estudiantes: ";
    cout<<endl;

    for(int i=0; i<5; i++){
        cout<<"codigo -> "<<codigo[i]<<" notas-> "<<notas[i]<<" faltas -> "<<faltas[i]<<endl;
    }
   
    for(int i=0; i<alum; i++){

        prom += notas[i];

    }

    cout<<"el promedio del salon es: "<<prom/alum<<endl;
    cout<<"el numero de desaprobados es: "<<contardesaprobado(notas, alum)<<endl;

    cout<<"ingrese el codigo del estudiante a buscar: ";
    cin>>clave;

    for(int i=0; i<alum; i++){
        if(codigo[i] == clave){
            cout<<"El estiante tiene: nota -> "<<notas[i]<<" faltas -> "<<faltas[i]<<" ranking -> "<<i + 1;
            break;
        }
    }
    cout<<endl;

    ordenarporcodigo(codigo, notas, faltas, alum);

    cout<<"ingrese el codigo del estudiante a buscar: ";
    cin>>clave;

    int indice = busquedabinaria(codigo, alum, clave);

    if(indice!=-1){
        cout<<"El estiante tiene: nota -> "<<notas[indice]<<" faltas -> "<<faltas[indice];
    }else{
        cout<<"no se encontro al alumno";
    }






    return 0;
}