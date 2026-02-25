#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ofstream archivo("venta.txt", ios::app);

    if(!archivo){
        cout<<"ERROR AL ABRIR EL ARCHIVO";
        return 1;
    }
    
    float ventas;
    float suma=0;
    float maximo, min;

    for(int i=0; i<7;i++){
        cout<<"Ingrese las ventas del dia "<<i+1<<": ";
        cin>>ventas;

        archivo<<ventas<<endl;

        suma +=ventas;

        if(i==0){
            maximo=ventas;
            min=ventas;
        }else{

            if(ventas>maximo){
                maximo = ventas;
            }
            if(ventas<min){
                min = ventas;
            }
        }

    }

    float promedio = suma/7;

    archivo<<"---------------------"<<endl;
    archivo<<"RESUMEN: "<<endl;
    archivo<<"TOTAL: "<<suma<<endl;
    archivo<<"PROMEDIO: "<<promedio<<endl;
    archivo<<"MAYOR VENTA: "<<maximo<<endl;
    archivo<<"MENOR VENTA: "<<min<<endl;

    archivo.close();



    return 0;
}