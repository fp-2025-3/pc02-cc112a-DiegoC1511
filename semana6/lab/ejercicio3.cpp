#include<iostream>
#include<fstream>
using namespace std;

struct Producto {
    int id;                  // Identificador único
    char nombre[30];         // Nombre del producto
    double precio;           // Precio unitario
    int stock;               // Cantidad disponible
    bool activo;             // true = activo, false = eliminado lógicamente

};

int buscarproductoporid(const char* inventario, int idbuscado){
    ifstream archivo("inventario.dat", ios::binary);

    if(!archivo){
        cout<<"ERROR AL ABRIR";
        return -1;
    }

    Producto p;
    int indice = 0;

    while(archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))){

        if(p.id==idbuscado && p.activo){
            archivo.close();

            return indice;
        }

        indice++;
    }

    archivo.close();
    return -1;
}

void registrarproductos(const char* inventario){

    ofstream archivo("inventario.dat", ios::binary | ios::app);

    if(!archivo){
        cout<<"ERROR AL ABRIR EL ARCHIVO";

        return;
    }

    int numprod;

    cout<<"INGRESE EL NUMERO DE ARTICULOS A REGISTRAR: ";
    cin>>numprod;

    for(int i=0; i<numprod; i++){
        Producto nuevo;

        do{
            cout<<"ID: ";
            cin>>nuevo.id;

            if(buscarproductoporid(inventario,nuevo.id)!=-1){
                cout<<"EL ID YA EXISTE. INTENTE OTRO";
            }

        }while(buscarproductoporid(inventario,nuevo.id)!=-1);

        cin.ignore();
        cout<<"NOMBRE: ";
        cin.getline(nuevo.nombre,30);

        do{
            cout<<"Precio (>0): ";
            cin>>nuevo.precio;
        }while(nuevo.precio <= 0);

        
        do{
            cout<<"Stock (>=0): ";
            cin>>nuevo.stock;
        }while(nuevo.stock < 0);

        nuevo.activo = true;

        archivo.write(reinterpret_cast<char*>(&nuevo),sizeof(Producto));

        cout<<"SE GUARDO CON EXITO"<<endl;
    }

    archivo.close();

}

void mostrarproductos(const char* inventario){

    ifstream archivo("inventario.dat", ios::binary);

    Producto p;

    

    while(archivo.read(reinterpret_cast<char*>(&p),sizeof(Producto))){

        if(p.activo){

            cout<<"ID: "<<"\t"<<p.id<<" NOMBRE: "<<"\t"<<p.nombre<<" PRECIO: "<<"\t"<<p.precio<<" STOCK: "<<"\t"<<p.stock<<endl;

        }

    }

    archivo.close();
}

void modificarprecio(const char* inventario, int id, double nuevoprecio){

    fstream archivo("inventario.dat", ios::binary|ios::in|ios::out);

    int pos = buscarproductoporid(inventario, id);

    if(pos == -1){
        cout<<"PRODUCTO NO ENCONTRADO";
        return;
    }

    Producto p;

    archivo.seekg(pos*sizeof(Producto));
    archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto));

    p.precio = nuevoprecio;

    archivo.seekp( pos*sizeof(Producto) );
    archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));

    archivo.close();
}

void eliminar(const char* inventario, int id){

    int pos = buscarproductoporid(inventario, id);
    if(pos==-1){
        cout<<"NO SE ENCONTRO EL PRODUCTO";
    }

    fstream archivo("inventario.dat", ios::binary|ios::in|ios::out);

    Producto p;

    archivo.seekg(pos*sizeof(Producto));
    archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto));

    p.activo = false;

    archivo.seekp(pos*sizeof(Producto));
    archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));

    archivo.close();
}

double calculartotal(const char* inventario){
    
    ifstream archivo("inventario.dat", ios::binary);

    if(!archivo){
        cout<<"ERROR AL ABRIR EL ARCHIVO";

    }
    Producto p;

    double total=0;

    while(archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))){
        total += (p.precio*p.stock);

    }

    archivo.close();

    return total;

}

int main(){

    const char* ruta = "inventario.dat";

    int opc, id;
    double p;

    do {
        cout << "\n--- MENU ALMACEN ---\n";
        cout << "1. Registrar\n2. Mostrar\n3. Buscar\n4. Modificar Precio\n5. Eliminar\n6. Valor Total\n7. Salir\nOpcion: ";
        cin >> opc;

        switch(opc) {
            case 1: registrarproductos(ruta); break;
            case 2: mostrarproductos(ruta); break;
            case 3: 
                cout << "ID a buscar: "; cin >> id;
                cout << "Posicion en archivo: " << buscarproductoporid(ruta, id) << endl;
                break;
            case 4:
                cout << "ID a modificar: "; cin >> id;
                cout << "Nuevo precio: "; cin >> p;
                modificarprecio(ruta, id, p);
                break;
            case 5:
                cout << "ID a eliminar: "; cin >> id;
                eliminar(ruta, id);
                break;
            case 6:
                cout << "Valor total del inventario: $" << calculartotal(ruta) << endl;
                break;
        }
    } while (opc != 7);

    return 0;

    return 0;
}