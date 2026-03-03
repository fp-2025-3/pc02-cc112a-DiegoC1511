#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ifstream archivo("entradas/baseUNI.txt");

    if(!archivo){
        cout<<"ERROR AL ABRIR ARCHIVO"<<endl;
    }

    string linea, nombres, apellidos, alummax;
    int num;
    double nota1, nota2, prom, promax=-1;

    while(getline(archivo, linea, '.')){
        num = stoi(linea);

        getline(archivo,apellidos, ',' );
        getline(archivo,nombres,'-');
        getline(archivo,linea,'-');

        nota1 = stof(linea);
        
        getline(archivo,linea);

        nota2 = stof(linea);

        prom = (nota1 + nota2)/2;

        if(prom>promax){
            promax = prom;
            alummax = nombres + " " + apellidos;

        }

        cout<<num<<"\t"<<apellidos<<"\t"<<nombres<<"\t"<<nota1<<"\t"<<nota2<<"\t"<<prom<<endl;
    }

    cout<<"PROMEDIO MAXIMO: "<<promax<<endl;
    cout<<"ALUMNO: "<<alummax<<endl;

    return 0;
}