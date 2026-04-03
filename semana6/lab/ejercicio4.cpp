#include<iostream>
#include<fstream>
using namespace std;

struct pasajero {
    int dni;
    char nombre[50];
};

struct asiento {
    int numero;
    bool reservado;
    pasajero* pasajero;   // nullptr si está libre
};

struct nodoreserva {
    pasajero pasajero;
    int numeroAsiento;
    nodoreserva* siguiente;
};

struct vuelo {
    char codigo[10];
    char destino[50];
    int capacidad;
    asiento* asientos;          // arreglo dinámico
    nodoreserva* listaReservas; // lista enlazada
};

void crearvuelo(vuelo &v){

    cout<<"CREAR VUELO: "<<endl;
    cout<<"CODIGO: ";
    cin>>v.codigo;
    cout<<"DESTINO: ";
    cin>>v.destino;
    cout<<"CAPACIDAD: ";
    cin>>v.capacidad;
    
    v.asientos = new asiento [v.capacidad];

    for(int i=0; i<v.capacidad; i++){
        v.asientos[i].numero = i + 1;
        v.asientos[i].pasajero = nullptr;
        v.asientos[i].reservado = false;
    }

    v.listaReservas = nullptr;
}

void mostrarmapadeasientos(const vuelo &v){

    for(int i=0; i<v.capacidad; i++){
        if(v.asientos[i].reservado){
            cout<<"[X]"<<endl;
        }else{
            cout<<"[ ]"<<endl;
        }
    }
}

void insertarlista(nodoreserva* &cabeza, pasajero p, int numasi ){

    nodoreserva* nuevo = new nodoreserva;

    nuevo->numeroAsiento = numasi;
    nuevo->pasajero = p;
    nuevo->siguiente=cabeza;

    cabeza = nuevo;


}

void reservarasiento(vuelo &v){

    cout<<"PROCESO DE RESERVA: "<<endl;

    pasajero* p = new pasajero;

    cout<<"DNI: ";
    cin>>p->dni;
    cout<<"NOMBRE: ";
    cin>>p->nombre;

    int numasi;
    cout<<"SELECCIONE EL NUMERO DE ASIENTO (1-"<<v.capacidad<<"): ";
    cin>>numasi;

    if(numasi<0||numasi>v.capacidad){
        cout<<"EL ASIENTO SELECCIONADO NO EXISTE";
        return;
    }

    if(v.asientos[numasi-1].reservado){
        cout<<"EL ASIENTO YA FUE RESERVADO";
        return;
    }

    v.asientos[numasi-1].reservado = true;
    v.asientos[numasi-1].pasajero = p;

    insertarlista(v.listaReservas,*p,numasi);

    cout<<"RESERVA EXITOSA"<<endl;

}

void cancelarreserva(nodoreserva* &cabeza){

    cout<<"PROCESO DE CANCELACION"<<endl;
    cout<<"----------------------"<<endl;

    if(cabeza==nullptr){
        cout<<"NO HAY ELEMENTOS PARA BORRAR";
        return;
    }

    nodoreserva* anterior=nullptr;
    nodoreserva* actual=cabeza;

    int dni;
    cout<<"INGRESE EL DNI PARA CANCELAR LA RESERVA: ";
    cin>>dni;

    while(actual != nullptr && actual->pasajero.dni != dni){
        anterior = actual;
        actual = actual->siguiente;
    }

    if(actual == nullptr){
        cout<<"NO SE ENCONTRRO";
        return;
    }
    if(anterior == nullptr){
        cabeza = actual->siguiente;
    }else{
        anterior->siguiente = actual->siguiente;
    }

    delete actual;

}

void mostrarlistapasajeros(nodoreserva* cabeza){
    cout<<"MOSTRAR PASAJEROS"<<endl;
    cout<<"--------------------"<<endl;

    nodoreserva* nuevo = cabeza;

    while(nuevo!=nullptr){
        cout<<"DNI: "<<nuevo->pasajero.dni<<"\t";
        cout<<"NOMBRE: "<<nuevo->pasajero.nombre<<"\t";
        cout<<"ASIENTO: "<<nuevo->numeroAsiento;
        cout<<endl;

        nuevo = nuevo->siguiente;
    }
}

void estadisticas(const vuelo &v, nodoreserva* cabeza){

    int asientosocupados = 0;
    int asientoslibres = 0;
    float ocupacion;

    ofstream archivo("reportevuelo.txt", ios::app);

    if(!archivo){
        cout<<"ERROR AL ABRIR EL ARCHIVO";
        return;
    }

    for(int i=0; i<v.capacidad; i++){
        if(v.asientos[i].reservado){
            asientosocupados ++;
        }else{
            asientoslibres ++;
        }
    }

    ocupacion = ((double)asientosocupados/v.capacidad)*100.0;

    archivo<<"REPORTE DE VUELO"<<endl;
    cout<<"REPORTE DE VUELO"<<endl;
    archivo<<"-----------------"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"CODIGO: "<<v.codigo<<endl;
    archivo<<"CODIGO: "<<v.codigo<<endl;
    cout<<"DESTINO: "<<v.destino<<endl;
    archivo<<"DESTINO: "<<v.destino<<endl;
    cout<<"CAPACIDAD: "<<v.capacidad<<endl;
    archivo<<"CAPACIDAD: "<<v.capacidad<<endl;
    cout<<"OCUPADOS: "<<asientosocupados<<endl;
    archivo<<"OCUPADOS: "<<asientosocupados<<endl;
    cout<<"LIBRES: "<<asientoslibres<<endl;
    archivo<<"LIBRES: "<<asientoslibres<<endl;
    cout<<"PORCENTAJE: "<<ocupacion<<"%"<<endl;
    archivo<<"PORCENTAJE: "<<ocupacion<<"%"<<endl;
   
    archivo<<"LISTAS DE PASAJEROS: "<<endl;
    cout<<"-----------------------"<<endl;
    archivo<<"----------------------"<<endl;
    cout<<"SE CREO LA LISTA DE PASAJEROS DENTRO DEL REPORTE";

    nodoreserva* nuevo = cabeza;

     while(nuevo!=nullptr){
        archivo<<"DNI: "<<nuevo->pasajero.dni<<"\t";
        archivo<<"NOMBRE: "<<nuevo->pasajero.nombre<<"\t";
        archivo<<"ASIENTO: "<<nuevo->numeroAsiento<<"\t";
        archivo<<endl;

        nuevo = nuevo->siguiente;
    }

    
}

void liberarmemoria(vuelo &v){

    for(int i=0; i<v.capacidad; i++){
        if(v.asientos[i].pasajero != nullptr){
            delete v.asientos[i].pasajero;
        }
    }
    delete[] v.asientos;

    while(v.listaReservas!=nullptr){
        nodoreserva* temp = v.listaReservas;
        v.listaReservas = v.listaReservas->siguiente;
        delete temp;
    }

}

int main(){

    vuelo miVuelo;
    miVuelo.asientos = nullptr;
    miVuelo.listaReservas = nullptr;

    int opcion;

    do {
        cout << "\n--- SISTEMA AEROPUERTO ---\n";
        cout << "1. Crear Vuelo\n2. Mostrar Mapa de Asientos\n3. Reservar Asiento\n";
        cout << "4. Cancelar Reserva\n5. Mostrar Pasajeros\n6. Estadisticas (generar reporte)\n7. Salir\nOpcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: crearvuelo(miVuelo); break;
            case 2: mostrarmapadeasientos(miVuelo); break;
            case 3: reservarasiento(miVuelo); break;
            case 4: cancelarreserva(miVuelo.listaReservas); break;
            case 5: mostrarlistapasajeros(miVuelo.listaReservas); break;
            case 6: estadisticas(miVuelo, miVuelo.listaReservas); break;
            case 7: liberarmemoria(miVuelo); break;
        }

    } while(opcion != 7);


    return 0;
}