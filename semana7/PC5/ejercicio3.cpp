#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int main(){

    const int columnas = 80;
    const int filas = 21;
    const double pi = 3.141592653589793;

    char grafico[filas][columnas];

    for(int i = 0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            grafico[i][j] = ' ';
        }
    }

    double paso = (2*pi)/(columnas-1);

    for(int i=0; i<columnas; i++){
        double x = i*paso;
        double y = sin(5*x);

        int fila =(int)((1-y)*(filas-1)/2);

        grafico[fila][i] = '*';

    }

    int ejeX = (filas - 1) / 2;
    for(int j = 0; j < columnas; j++) {
        if(grafico[ejeX][j] == ' ')
            grafico[ejeX][j] = '-';
    }

    for(int i = 0; i < filas; i++) {
        if(grafico[i][0] == ' ')
            grafico[i][0] = '|';
    }

    
    ofstream archivo("grafico.txt");

    if(!archivo) {
        cout << "Error al crear el archivo" << endl;
        return 1;
    }

    
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            archivo << grafico[i][j];
        }
        archivo << endl;
    }

    archivo.close();

    cout << "Archivo grafico.txt generado correctamente." << endl;

    return 0;



    return 0;
}