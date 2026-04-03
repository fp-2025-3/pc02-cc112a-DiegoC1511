#include<iostream>
using namespace std;

struct proceso{
    int id;
    string nombre;
    float memoria;
    proceso* siguiente;
};

struct listadeprocesos{
    proceso* cabeza;
    int contador;
};

void inicializar(listadeprocesos &lista){
    lista.cabeza = nullptr;
    lista.contador = 0;
}

proceso* crearnodo(int id, const string& nombre, float memoria){
    proceso* nuevo = new proceso;

    nuevo->id = id;
    nuevo->nombre=nombre;
    nuevo->memoria=memoria;
    nuevo->siguiente = nullptr;

    return nuevo;
}

void insertaralinicio(listadeprocesos &lista, int id, const string& nombre, float memoria){
    proceso* nuevo =  crearnodo(id, nombre, memoria);

    nuevo->siguiente = lista.cabeza;
    lista.cabeza = nuevo;
    lista.contador++;
}

void insertaralfinal(listadeprocesos &lista, int id, const string& nombre, float memoria){

    proceso* nuevo = crearnodo(id, nombre, memoria);

    if(lista.cabeza == nullptr){
        lista.cabeza = nuevo;
    }else{
        proceso* temp = lista.cabeza;
        while(temp->siguiente != nullptr){
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
    lista.contador++;
}

void mostrarlista(const listadeprocesos &lista){

    cout<<"ESTADO DEL SISTEMA (El sistema tiene "<<lista.contador<<" procesos): "<<endl;
    proceso* temp = lista.cabeza;

    if(temp == nullptr){
        cout<<"SISTEMA VACIO";
        return;
    }

    while(temp != nullptr){
        cout<<"ID: "<<temp->id<<endl;
        cout<<"NOMBRE: "<<temp->nombre<<endl;
        cout<<"MEMORIA: "<<temp->memoria<<endl;

        temp = temp->siguiente;
        
    }
}
void buscarprocesoporid(const listadeprocesos &lista, int id){

    proceso* temp = lista.cabeza;

    while(temp != nullptr){
        if(temp->id == id){
            cout<<"BUSQUEDA: proceso "<<id<<" encontrado("<<temp->nombre<<" )";
            return;
        }
        temp = temp->siguiente;
    }

    cout<<"BUSQUEDA: proceso "<<id<<" no encontrado en el sistema.";
}

void eliminarproceso(listadeprocesos &lista, int id){

    proceso* actual = lista.cabeza;
    proceso* anterior = nullptr;

    while(actual != nullptr && actual->id != id){
        anterior = actual;
        actual = actual->siguiente;
    }

    if(actual == nullptr){
        cout<<"Eliminar: ID "<<id<<" no encontrado. ";
        return;
    }
    if(anterior == nullptr){
        lista.cabeza = actual->siguiente;
    }else{
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
    lista.contador--;
    
    cout<<"ELIMINAR: ID "<<id<<" eliminado con exito.";
}

void insertarpororden(listadeprocesos &lista, int id, const string& nombre, float memoria){
    proceso* nuevo = crearnodo(id, nombre, memoria);

    if(lista.cabeza==nullptr || lista.cabeza->memoria >= memoria){
        nuevo->siguiente = lista.cabeza;
        lista.cabeza = nuevo;
    }else{
        proceso*actual = lista.cabeza;
        
        while(actual->siguiente != nullptr && actual->siguiente->memoria < memoria){
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual-> siguiente;
        actual->siguiente = nuevo;
    }

    lista.contador++;
}

void liberarespacio(listadeprocesos &lista){

    proceso* actual = lista.cabeza;
    while(actual != nullptr){
        proceso* sig = actual->siguiente;
        delete actual;
        actual = sig;
    }

    lista.cabeza = nullptr;
    lista.contador = 0;

    cout<<"Toda la memoria se libero. ";
}



int main(){

    listadeprocesos miSistema;
    inicializar(miSistema);

    insertaralinicio(miSistema, 101, "Init", 10.5);
    insertaralinicio(miSistema, 102, "Bash", 25.0);
    insertaralinicio(miSistema, 103, "Cron", 5.2);

    insertaralfinal(miSistema, 201, "Daemon", 100.0);
    insertaralfinal(miSistema, 202, "Python_App", 150.8);

    mostrarlista(miSistema);

    buscarprocesoporid(miSistema, 201);
    buscarprocesoporid(miSistema, 999);

    eliminarproceso(miSistema, 101);
    mostrarlista(miSistema);

    cout << "\nInsertando proceso ordenado (50 MB)...\n";
    insertarpororden(miSistema, 305, "Worker", 50.0);
    mostrarlista(miSistema);

    liberarespacio(miSistema);

    return 0;

}
