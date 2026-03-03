#include<iostream>
#include<fstream>
using namespace std;

struct Venta {
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};


int main(){

    ifstream archivo1("entradas/ventas.dat", ios::binary);
    ofstream archivo2("reporte.txt");

    if(!archivo1){
        cout<<"ERROR AL ABRIR ARCHIVO1";

        return -1;
    }

    if(!archivo2){
        cout<<"ERROR AL ABRIR ARCHIVO2";

        return -1;
    }
    
    int total;
    double monto=0;
    double vendeores[10] = {0};
    double producto[20] = {0};
    

    archivo1.read(reinterpret_cast<char*>(&total), sizeof(int));

    Venta registro;

    for(int i=0; i<total; i++){

        archivo1.read(reinterpret_cast<char*>(&registro), sizeof(Venta));

        monto += registro.cantidad*registro.precioUnitario;

        if(registro.idVendedor >= 1 && registro.idVendedor <= 10){

        vendeores[registro.idVendedor-1] += registro.cantidad*registro.precioUnitario;
        }

        if(registro.idProducto >= 1 && registro.idProducto <= 20){

        producto[registro.idProducto-1] += registro.cantidad;
        
        }

    }

    int indice1 = 0;
    int indice2 = 0;

    for(int i=1; i<20; i++){
        if(producto[i]>producto[indice2]){
            indice2 = i;
        }
    }

    for(int i=1; i<10; i++){
        if(vendeores[i]>vendeores[indice1]){
            indice1 = i;
        }
    }

    archivo1.clear();
    archivo1.seekg(sizeof(int), ios::beg);

    archivo2<<"------ REPORTE GENERAL DE VENTAS -------"<<endl;
    archivo2<<"Total de registos: "<<total<<endl;
    archivo2<<endl;
    archivo2<<"Monto total vendido: "<<monto<<endl;
    archivo2<<endl;
    archivo2<<"----------------------------------------"<<endl;
    archivo2<<endl;
    archivo2<<"VENDEDOR CON MAYOR RECAUDACION"<<endl;
    archivo2<<"ID vendedor: "<<indice1+1<<endl;
    archivo2<<"Total unidades: "<<vendeores[indice1]<<endl;
    archivo2<<endl;
    archivo2<<"----------------------------------------"<<endl;
    archivo2<<endl;
    archivo2<<"PRODUCTO MAS VENDIDO"<<endl;
    archivo2<<"ID producto: "<<indice2+1<<endl;
    archivo2<<"Total unidades: "<<producto[indice2]<<endl;
    archivo2<<endl;
    archivo2<<"----------------------------------------"<<endl;
    archivo2<<endl;
    archivo2<<"VENTAS SOSPECHOSAS (cantidad > 100)"<<endl;

    for(int i=0; i<total; i++){
        archivo1.read(reinterpret_cast<char*>(&registro), sizeof(Venta));
        if(registro.cantidad>100){
            archivo2<<"ID venta: "<<registro.idVenta<<" | Vendedor: "<<registro.idVendedor<<" | Producto: "<<registro.idProducto<<" | Cantidad: "<<registro.cantidad<<endl;
        }
        
    }

    archivo1.close();
    archivo2.close();

    return 0;
}


