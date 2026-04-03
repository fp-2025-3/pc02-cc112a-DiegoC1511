#include<iostream>
#include<cmath>
using namespace std;

struct termino{
    int exponente;
    double coeficiente;
};

struct polinomio{
    int cant;
    termino *terminos;
};

void crearpolinomio(polinomio &p, int n ){

    p.cant = n;
    p.terminos = new termino[n];
  
}

void leerpolinomio(polinomio &p){

    for(int i=0; i<p.cant; i++){
        cout<<"INGRESE EL TERMINO NUMERO "<<i+1<<": ";
        cin>>p.terminos[i].coeficiente;
        cout<<"  EXPONENTE: ";
        cin>>p.terminos[i].exponente;
    }
}

void mostrarpolinomio(polinomio &p){

    for(int i=0; i<p.cant-1; i++){
        for(int j=0; j<p.cant-1-i; j++){
            if(p.terminos[j].exponente<p.terminos[j+1].exponente){
                swap(p.terminos[j],p.terminos[j+1]);
            }
        }
    }

    cout<<"MOSTRANDO POLINOMIO: "<<endl;

    for(int i=0; i<p.cant; i++){
        
        if(i == p.cant-1){
            cout<<p.terminos[i].coeficiente<<"x^"<<p.terminos[i].exponente<<endl;
        }else{
            cout<<p.terminos[i].coeficiente<<"x^"<<p.terminos[i].exponente<<" + ";
        }   
    }
}

void reducirpolinomio(polinomio &p){
    for(int i=0;i<p.cant; i++){
        for(int j=i+1; j<p.cant;j++){
            if(p.terminos[i].exponente==p.terminos[j].exponente){
                p.terminos[i].coeficiente += p.terminos[j].coeficiente;

                for(int k=j; k<p.cant-1;k++){
                p.terminos[k] = p.terminos[k+1];
                }

                p.cant--;
                j--;
            }

            
        }
    }
}

double evaluarpolinomio(polinomio p, double x){

    double resultado = 0;

    for(int i=0; i<p.cant; i++){

        resultado += p.terminos[i].coeficiente * pow(x,p.terminos[i].exponente);
    }

    return resultado;
}

void derivarpolinomio(polinomio &p, polinomio &der){

    der.cant = p.cant;
    der.terminos = new termino[der.cant];

    int k=0;

    for(int i=0; i<p.cant; i++){
        if(p.terminos[i].exponente != 0){
            der.terminos[i].coeficiente = p.terminos[i].coeficiente*p.terminos[i].exponente;
            der.terminos[i].exponente = p.terminos[i].exponente - 1;

            k++;
        }
    }

    der.cant = k;
}

void liberarmemoria(polinomio &p, polinomio &der){

    delete[] p.terminos;
    delete[] der.terminos;

    p.terminos = nullptr;
    der.terminos = nullptr;

}




int main(){

    polinomio p;
    polinomio der;
    double num, resul;


    crearpolinomio(p,5);
    leerpolinomio(p);
    mostrarpolinomio(p);
    cout<<endl;
    reducirpolinomio(p);
    cout<<endl;
    mostrarpolinomio(p);
    cout<<endl;
    cout<<"INGRESE EL NUMERO A EVALUAR: ";
    cin>>num;
    resul = evaluarpolinomio(p,num);
    cout<<"EL POLINOMIO EVALUADO EN "<<num<<" ES: "<<resul<<endl;
    derivarpolinomio(p,der);
    mostrarpolinomio(der);
    liberarmemoria(p, der);


    


    return 0;
}