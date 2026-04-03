#include<iostream>
#include<fstream>
using namespace std;

struct estudiante{

    int id;
    char nombre[50];
    float promedio;
   
};

void registrarestudiante(){

    ofstream  archivo( "estudiantes.dat" , ios::binary | ios::app);

    if(!archivo){
        return;
    }

    int n;
    cout<<"Cuantos estudiantes se registraran: ";
    cin>>n;

    for(int i=0; i<n; i++){
        estudiante e;
        cout<<"ID: ";
        cin>>e.id;
        cout<<"NOMBRE: ";
        cin.ignore();
        cin.getline(e.nombre, 50);
        cout<<"PROMEDIO: ";
        cin>>e.promedio;

        archivo.write(reinterpret_cast<char*>(&e), sizeof(estudiante));
    }

    archivo.close();

}

void mostrartodos(){

    ifstream archivo("estudiantes.dat", ios::binary);
    if(!archivo){
        return;
    }

    estudiante e;

    while(archivo.read(reinterpret_cast<char*>(&e), sizeof(estudiante))){
        cout<<"ID: "<<e.id<<"\t"<<"  NOMBRE: "<<e.nombre<<"\t"<<"  PROMEDIO: "<<e.promedio<<endl;
    }

    archivo.close();
}

void modificarestudiante(){
    fstream archivo("estudiantes.dat", ios::binary | ios::in | ios::out);

    int pos;
    cout<<"Que numero de registro desea modificar? (0 es el promero): ";
    cin>>pos;

    archivo.seekp(pos*sizeof(estudiante));

    estudiante e;

    cout<<"NUEVO ID: ";
    cin>>e.id;
    cout<<"NUEVO NOMBRE: ";
    cin.ignore();
    cin.getline(e.nombre, 50);
    cout<<"NUEVO PROMEDIO: ";
    cin>>e.promedio;

    archivo.write(reinterpret_cast<char*>(&e), sizeof(estudiante));
    archivo.close();
}


int main(){

    int op;
    do {
        cout << "\n1. Registrar\n2. Mostrar\n3. Modificar\n4. Salir\nOpción: ";
        cin >> op;
        if(op == 1){
            registrarestudiante();
        }else if(op == 2){
            mostrartodos();
        }else if(op == 3){
            modificarestudiante();
        } 
    }while (op != 4);
    return 0;

    
}