#include<iostream>
#include<cmath>
using namespace std;

struct polinomio{
    
    int grado;
    double* coef;

};

void formarpolinomio(polinomio &p, string nombre){

    cout<<"Ingrese el grado del "<<nombre<<" polinomio: ";
    cin>>p.grado;

    p.coef = new double [p.grado + 1];

    for(int i=p.grado; i>=0; i--){
        cout<<"ingrese coeficiente de x^ "<<i<<": ";
        cin>>p.coef[i];
    }

}

void mostrarpolinomio(polinomio &p,string nombre){

    cout<<nombre<<" polinomio: ";
    for(int i=p.grado; i>=0; i--){
        cout<<p.coef[i]<<"x^"<<i;
        if(i>0){
            cout<<" + ";
        }
    }
}

void sumar(polinomio p1, polinomio p2){

    int gradomax = max(p1.grado, p2.grado);
    polinomio res;
    res.grado = gradomax;

    res.coef = new double[gradomax + 1]{0};

    for(int i=0; i<=gradomax; i++){
        if(i<=p1.grado){
            res.coef[i] += p1.coef[i]; 
        }
        if(i<=p2.grado){
            res.coef[i] += p2.coef[i];
        }
    }


    mostrarpolinomio(res, "suma");

    delete[] res.coef;

    res.coef = nullptr; 
}

void producto(polinomio p1, polinomio p2){

    int gradomax = p1.grado + p2.grado;

    polinomio res;

    res.grado = gradomax;

    res.coef = new double [ gradomax + 1 ]{0}; 

    for(int i=0; i<=p1.grado; i++){
        for(int j=0; j<=p2.grado; j++){

            res.coef[i+j]+=p1.coef[i]*p2.coef[j];
        }
    }

    mostrarpolinomio(res, "producto");

    delete[] res.coef;

    res.coef = nullptr;

}

int evaluar(polinomio p1, int valor){

    int suma = 0;

    for(int i=0; i<=p1.grado; i++){
        suma += p1.coef[i]*pow(valor,i);

    }

    return suma;
}

int main(){

    polinomio p1;
    polinomio p2;
    int valor;

    formarpolinomio(p1, "primero");
    cout<<endl;
    formarpolinomio(p2, "segundo");
    cout<<endl;
    mostrarpolinomio(p1,"primero");
    cout<<endl;
    mostrarpolinomio(p2, "segundo");
    cout<<endl;
    sumar(p1, p2);
    cout<<endl;
    producto(p1, p2);
    cout<<endl;
    cout<<" Ingrese el valor de x para evaluar en el primer polinomio: ";
    cin>>valor;
    cout<<" El primer polinomio evaluado en "<<valor<<" es: "<<evaluar(p1, valor);

    return 0;

    delete[] p1.coef;
    delete[] p2.coef;

}