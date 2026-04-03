#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ofstream creador("notas.txt");

    if (creador) {
       
        creador << 15 << endl;
        creador << 18 << endl;
        creador << 12 << endl;
        creador << 9 << endl;
        creador << 20 << endl;
        creador << 14 << endl;
        creador << 16 << endl;
        creador << 11 << endl;

        creador.close();
        cout << "Archivo 'notas.txt' creado exitosamente." << endl;
        
    } else {
        cout << "Error al crear el archivo." << endl;
    }

    ifstream entrada("notas.txt");

    if(!entrada){
        cout<<"error: no se encontro notas.txt";
        return 1;
    }
    int nota;
    int total=0, aprobados=0, desaprobados =0;
    int mayor, menor;
    float suma =0;

    if(entrada>>nota){
        total = 1;
        suma=nota;
        mayor = nota;
        menor =nota;
        if(nota>=10){
            aprobados++;
        }else{
            desaprobados++;
        }

        while(entrada>>nota){
            total ++;
            suma += nota;
            if(nota>=10){
                aprobados++;
            }else{
                desaprobados++;
            }
            if(nota>mayor){
                mayor = nota;
            }
            if(nota<menor){
                menor = nota;
            }
        }
    }
    entrada.close();

    if(total==0){
        cout<<"REPORTE VACIO"<<endl;
        return 0;
    }

    ofstream salida("reporte.txt");
    
    if(!salida){
        cout<<"error al iniciar el programa";
        return 1;
    }
    float promedio = suma/total;

    salida<<"REPORTE GENERAL: "<<endl;
    salida<<"------------------"<<endl;
    salida<<endl;
    salida<<"TOTAL DE ESTUDIANTES: "<<total<<endl;
    salida<<"PROMEDIO: "<<promedio<<endl;
    salida<<"MAYOR NOTA: "<<mayor<<endl;
    salida<<"MENOR NOTA: "<<menor<<endl;
    salida<<"APRONADOS: "<<aprobados<<endl;
    salida<<"DESAPROBADOS: "<<desaprobados<<endl;

    salida.close();

    return 0;
}

