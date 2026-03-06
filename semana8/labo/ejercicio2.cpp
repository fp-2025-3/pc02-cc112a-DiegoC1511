#include <iostream>
#include <fstream>

using namespace std;

struct CuentaBancaria {
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};


void crearCuentas(int N) {

    fstream archivo("cuentas.dat", ios::binary | ios::in | ios::out);

    if(!archivo){
        archivo.open("cuentas.dat", ios::out | ios::binary);
        archivo.close();

        archivo.open("cuentas.dat", ios::in | ios::out | ios::binary);
    }

    CuentaBancaria cuenta;

    for(int i=0; i<N; i++){

        cout<<"Ingrese numero cuenta bancaria: ";
        cin>>cuenta.numeroCuenta;

        int posicion = (cuenta.numeroCuenta-1)*sizeof(CuentaBancaria);

        archivo.seekg(posicion);

        CuentaBancaria temp;
        archivo.read((char*)&temp, sizeof(CuentaBancaria));

        if(archivo){
            cout<<"Ya existe una cuenta con ese numero"<<endl;
            i--;
        }

        archivo.clear();
        archivo.seekp(posicion);

        cout<<"Ingrese nombre de titular: ";
        cin>>cuenta.titular;
        cout<<"Ingrese saldo inicial: ";
        cin>>cuenta.saldo;

        cuenta.activa = true;

        archivo.write((char*)&cuenta, sizeof(CuentaBancaria));
    }

    archivo.close();
    
}

void buscarcuenta( int numcuenta){

    ifstream archivo("cuentas.dat", ios::binary | ios::in);

    if(!archivo){
        cout<<"ERROR AL ABRIR ARCHIVO"<<endl;
        return ;
    }

    CuentaBancaria cuenta;

    archivo.seekg((numcuenta-1)*sizeof(CuentaBancaria));

    if(archivo.read((char*)&cuenta, sizeof(CuentaBancaria))){
        cout<<"---MOSTRAR CUENTA SELECCIONADA---"<<endl;
        cout<<endl;
        cout<<"Numero cuenta: "<<cuenta.numeroCuenta<<endl;
        cout<<"Titular: "<<cuenta.titular<<endl;
        cout<<"Saldo: "<<cuenta.saldo<<endl;
        if(cuenta.activa){
            cout<<"CUENTA ACTIVA"<<endl;
        }else{
            cout<<"CUENTA INACTIVA"<<endl;
        }
    }else{
        cout<<"NO SE ENCONTRO LA CUENTA"<<endl;
    }
     
    archivo.close();
}

/*void retirarodepositar(int numcuenta){

    fstream archivo("cuentas.dat", ios::binary | ios::in | ios::out);

    if(!archivo){
        cout<<"ERROR AL ABRIR ARCHIVO";
    }

    CuentaBancaria cuenta;
    int posicion = (numcuenta-1)*sizeof(CuentaBancaria);

    archivo.seekg(posicion);
    archivo.read((char*)&cuenta, sizeof(CuentaBancaria));

    int opcion;
    double monto;

    
    do{
        cout<<"1. RETIRO"<<endl;
        cout<<"2. DEPOSITO"<<endl;
        cout<<"3. SALIR"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:

            cout<<"Monto a retirar: ";
            cin>>monto;

            if(cuenta.saldo-monto<0){
                cout<<"SALDO INSUFICIENTE";
                break;
            }else{
                archivo.seekg((numcuenta-1)*sizeof(CuentaBancaria));
                archivo.read((char*)&cuenta, sizeof(CuentaBancaria));
                cuenta.saldo = cuenta.saldo - monto;
                archivo.seekp((numcuenta-1)*sizeof(CuentaBancaria));
                archivo.write((char*)&cuenta, sizeof(CuentaBancaria));
            }

            break;
            case 2:

            cout<<"Monto a depositar: ";
            cin>>monto;

            archivo.seekg((numcuenta-1)*sizeof(CuentaBancaria));
            archivo.read((char*)&cuenta, sizeof(CuentaBancaria));
            cuenta.saldo = cuenta.saldo + monto;
            archivo.seekp((numcuenta-1)*sizeof(CuentaBancaria));
            archivo.write((char*)&cuenta, sizeof(CuentaBancaria));

            break;

        default:

        cout<<"INGRESE UNA OPCION VALIDA";

        }


    }while(opcion !=3);

    cout<<"SE HA ACTUALIZADO CORRECTAMENTE EL SALDO"<<endl;
    cout<<endl;
    buscarcuenta(numcuenta);

    archivo.close();

}*/

void retirarodepositar(int numcuenta) {
    // Abrimos el archivo en modo lectura/escritura binaria
    fstream archivo("cuentas.dat", ios::binary | ios::in | ios::out);

    if (!archivo) {
        cout << "ERROR AL ABRIR ARCHIVO" << endl;
        return;
    }

    CuentaBancaria cuenta;
    long int posicion = (numcuenta - 1) * sizeof(CuentaBancaria);

    // 1. PRIMERO cargamos los datos de la cuenta para que 'cuenta.saldo' tenga valor
    archivo.seekg(posicion);
    if (!archivo.read((char*)&cuenta, sizeof(CuentaBancaria)) || cuenta.numeroCuenta != numcuenta) {
        cout << "LA CUENTA NO EXISTE." << endl;
        archivo.close();
        return;
    }

    int opcion;
    double monto;

    do {
        cout << "\n--- MENU DE TRANSACCION (Cuenta: " << cuenta.numeroCuenta << ") ---" << endl;
        cout << "Saldo actual: " << cuenta.saldo << endl;
        cout << "1. RETIRO" << endl;
        cout << "2. DEPOSITO" << endl;
        cout << "3. SALIR" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 3){
            break; // Salida limpia

        } 

        switch (opcion) {
            case 1:
                cout << "Monto a retirar: ";
                cin >> monto;

                if (cuenta.saldo - monto < 0) {
                    cout << "ERROR: SALDO INSUFICIENTE" << endl;
                } else {
                    cuenta.saldo -= monto; // Actualizamos la variable en memoria
                    
                    // GUARDAR EN DISCO
                    archivo.clear(); // Limpiar flags de error por si acaso
                    archivo.seekp(posicion); // Regresar al lugar correcto
                    archivo.write((char*)&cuenta, sizeof(CuentaBancaria));
                    archivo.flush(); // Forzar la escritura en el archivo físico
                    cout << "Retiro exitoso." << endl;
                }
                break;

            case 2:
                cout << "Monto a depositar: ";
                cin >> monto;

                cuenta.saldo += monto; // Actualizamos memoria
                
                // GUARDAR EN DISCO
                archivo.clear();
                archivo.seekp(posicion);
                archivo.write((char*)&cuenta, sizeof(CuentaBancaria));
                archivo.flush();
                cout << "Deposito exitoso." << endl;
                break;

            default:
                cout << "INGRESE UNA OPCION VALIDA" << endl;
                break;
        }

    } while (opcion != 3);

    archivo.close();
    
    cout << "\n--- ACTUALIZACION FINAL ---" << endl;
    buscarcuenta(numcuenta);
}

void desactivarcuentas(int numcuenta){

    fstream archivo("cuentas.dat", ios::binary | ios::in | ios::out);

    if(!archivo){
        cout<<"ERROR AL ABRIR ARCHIVO";
    }
    
    int posicion = (numcuenta-1)*sizeof(CuentaBancaria);

    CuentaBancaria cuenta;

    archivo.seekg(posicion);
    archivo.read((char*)&cuenta, sizeof(CuentaBancaria));

    cuenta.activa = false;

    archivo.seekp(posicion);
    archivo.write((char*)&cuenta, sizeof(CuentaBancaria));

    cout<<"CUENTA DESACTIVADA CORRECTAMENTE"<<endl;

    archivo.close();

}

void mostarcuentasactivas(){

    ifstream archivo("cuentas.dat", ios::binary | ios::in);

    if(!archivo){
        cout<<"ERROR AL ABRIR ARCHIVO";
    }

    CuentaBancaria cuenta;

    cout<<"---MOSTRAR CUENTAS ACTIVAS---"<<endl;
    cout<<endl;

    while(archivo.read(reinterpret_cast<char*>(&cuenta), sizeof(CuentaBancaria))){

        if(cuenta.activa){
            
            cout<<"Numero cuenta: "<<cuenta.numeroCuenta<<endl;
            cout<<"Titular: "<<cuenta.titular<<endl;
            cout<<"Saldo: "<<cuenta.saldo<<endl;
            cout<<"----------------------------------------"<<endl;
        }

    }

    archivo.close();

}


int main() {

    int opcion;

    do{
        cout<<"1. Crear cuentas"<<endl;
        cout<<"2. Buscar cuenta"<<endl;
        cout<<"3. Retirar o Depositar"<<endl;
        cout<<"4. Desactivar cuenta"<<endl;
        cout<<"5. Mostrar cuentas activas"<<endl;
        cout<<"6. Salir"<<endl;
        cin>>opcion;

        switch (opcion){

            case 1:
                int cuentas;
                cout<<"Ingrese el numero de cuentas";
                cin>>cuentas;
                crearCuentas(cuentas);
                break;
            
            case 2: 
                int numcuenta;
                cout<<"Ingrese numero de cuenta a buscar: ";
                cin>>numcuenta;
                buscarcuenta(numcuenta);
                break;
            
            case 3:
                int numcuenta1;
                cout<<"Ingrese numero de cuenta donde lo realizara: ";
                cin>>numcuenta1;

                retirarodepositar(numcuenta1);
                break;

            case 4: 
                int numcuenta2;
                cout<<"Ingrese numero de cuenta a desactivar: ";
                cin>>numcuenta2;

                desactivarcuentas(numcuenta2);
                break;
            
            case 5:
                mostarcuentasactivas();
                break;
            
            case 6:
                cout<<"SALIENDO...";
                break;
            
            default: 
                cout<<"Ingrese una opcion valida";
                break;
               

        }

    }while(opcion != 6);
  
    return 0;
}