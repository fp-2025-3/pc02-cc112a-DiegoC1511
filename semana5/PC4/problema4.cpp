#include<iostream>
#include<cstring>
using namespace std;

struct item{

    char* descripcion;
    int cantidad;
    double preciounitario;

};

struct pedido{
    
    int numeropedido;
    char* nombrecliente;
    item* items;
    int cantidaditem;
};

item crearitem(const char* descripcion, int cantidad, double precio){

    item nuevo;

    nuevo.descripcion = new char [strlen(descripcion)+1];
    strcpy(nuevo.descripcion, descripcion);
    nuevo.cantidad = cantidad;
    nuevo.preciounitario = precio;

    return nuevo;
}

pedido* crearpedido(int numero, const char* cliente, int cantidaditem){

    pedido* nuevo = new pedido;

    nuevo ->cantidaditem = cantidaditem;
    nuevo->numeropedido = numero;
    nuevo->nombrecliente = new char[ strlen(cliente) + 1];
    strcpy(nuevo->nombrecliente, cliente);
    nuevo->items = new item[cantidaditem];

    return nuevo;

}

double calculartotal(const pedido* p){
    double total =0;
    for(int i=0; i<p->cantidaditem; i++){
        total+=(p->items[i].cantidad*p->items[i].preciounitario);
    }

    return total;
}

item* itemmascaro(pedido *p){
    if(p == nullptr || p->cantidaditem==0){
        return nullptr;
    }

    item* caro = &p->items[0];

    for(int i=0; i< p->cantidaditem; i++){
        if(p->items[i].preciounitario > caro->preciounitario){
            caro = &p->items[i];
        }
    }

    return caro;

}

void mostrarpedido(pedido* p){

    cout<<"ITEMS: "<<endl;
    for(int i=0; i<p->cantidaditem; i++){

        cout<<p->items[i].descripcion<<"\t"<<p->items[i].cantidad<<"\t"<<p->items[i].preciounitario<<endl;
        
    }
}

void liberarpedido(pedido* p){

    if(p==nullptr){
        return;
    }

    for(int i=0; i< p->cantidaditem; i++){
        delete[] p->items[i].descripcion;
    }

    delete[] p->items;

    delete[] p->nombrecliente;

    delete[] p;
}


int main(){

    pedido* mipedido = crearpedido(101, "Carlos Perez", 3);

    mipedido->items[0] = crearitem("laptop", 1, 100);
    mipedido->items[1] = crearitem("mouse", 2, 200);
    mipedido->items[2] = crearitem("teclado", 3, 300);

    cout<<"Pedido N°: "<<mipedido->numeropedido<<endl;
    cout<<endl;
    cout<<"Cliente: "<<mipedido->nombrecliente<<endl;
    cout<<endl;

    mostrarpedido(mipedido);
    cout<<endl;

    cout<<"calcular total: "<<calculartotal(mipedido)<<endl;

    item* caro = itemmascaro(mipedido);

    cout<<"item mas caro: "<<caro->descripcion<<" "<<caro->preciounitario<<endl;

    liberarpedido(mipedido);


    return 0;
}