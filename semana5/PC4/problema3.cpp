#include<iostream>
#include<cstring>
using namespace std;

struct producto{
    int codigo;
    char* nombre;
    double precio;
    int stock;

};

producto crearproducto(int codigo, const char*nombre, double precio, int stock){
    producto nuevo;

    int tam = strlen(nombre);

    nuevo.codigo = codigo;
    nuevo.nombre = new char[tam + 1];
    nuevo.precio = precio;
    nuevo.stock = stock;

    return nuevo;
}

producto* crearinventario(int n){

    producto* A = new producto [n];

    A[0] = crearproducto(100, "teclado", 10.5, 5 );
    A[1] = crearproducto(101, "mouse", 21, 10);
    A[2] = crearproducto(102, "monitor", 31, 15);
    A[3] = crearproducto(103, "laptop", 42, 20);
    A[4] = crearproducto(104, "impresora", 52.5, 25);

}

producto* buscarproducto(producto* inventario, int codigobuscado){

    while(inventario != nullptr){
        if(inventario->codigo == codigobuscado){
            return inventario;
        }
        inventario++;
    }

    return nullptr;

}

void mostrarinventario(producto* inventario){
    while(inventario != nullptr){
        cout<<"codigo: "<<inventario->codigo;
        cout<<" nombre: "<<inventario->nombre;
        cout<<" precio: "<<inventario->precio;
        cout<<" stock: "<<inventario->stock;
        cout<<endl;
        inventario++;
    }
}

void liberarmemoria(producto* inventario, int n){

    for(int i=0; i<n; i++){
        delete inventario[i].nombre;
    }

    delete[] inventario;
}



int main(){

    producto* inventario = crearinventario(5);

    mostrarinventario(inventario);

    

    if(buscarproducto(inventario, 102) != nullptr){
        cout<<"buscando producto con codigo 102 ..."<<endl;
        cout<<"producto encontrado: "<<inventario->nombre<<" precio: "<<inventario->precio;

    }else{
        cout<<"no se encontro";
    }

    liberarmemoria(inventario, 5);

   

    return 0;
}