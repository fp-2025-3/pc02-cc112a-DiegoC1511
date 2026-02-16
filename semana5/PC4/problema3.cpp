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
    strcpy(nuevo.nombre, nombre);
    nuevo.precio = precio;
    nuevo.stock = stock;

    return nuevo;
}

producto* crearinventario(int n){

    producto* A = new producto [n];

    A[0] = crearproducto(100, "teclado", 10.5, 5 );
    A[1] = crearproducto(101, "mouse", 21, 10);
    A[2] = crearproducto(102, "monitor", 31.5, 15);
    A[3] = crearproducto(103, "laptop", 42, 20);
    A[4] = crearproducto(104, "impresora", 52.5, 25);

    return A;

}

producto* buscarproducto(producto* inventario, int codigobuscado, int n){

   for (int i = 0; i < n; i++) {
        if (inventario[i].codigo == codigobuscado) {
            return &inventario[i]; // Retorna la dirección del producto encontrado
        }
    }
    return nullptr;


}

void mostrarinventario(producto* inventario, int n){
     for (int i = 0; i < n; i++) {
        cout<<"codigo: "<<inventario[i].codigo;
        cout<<" nombre: "<<inventario[i].nombre;
        cout<<" precio: "<<inventario[i].precio;
        cout<<" stock: "<<inventario[i].stock;
        cout<<endl;
    }
}

void liberarmemoria(producto* inventario, int n){

    for(int i=0; i<n; i++){
        delete[] inventario[i].nombre;
    }

    delete[] inventario;
}



int main(){

    producto* inventario = crearinventario(5);

    mostrarinventario(inventario, 5);

    producto* encontrado = buscarproducto(inventario, 102, 5);

    cout<<"buscando producto con codigo 102 ..."<<endl;

    if(encontrado != nullptr){
        
        cout<<"producto encontrado: "<<encontrado->nombre<<" precio: "<<encontrado->precio;

    }else{
        cout<<"no se encontro";
    }

    liberarmemoria(inventario, 5);

   

    return 0;
}