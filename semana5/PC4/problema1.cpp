#include<iostream>
using namespace std;

struct polinomio{

    int grado;
    double* coef;
    
};

void sumarpolinomio(polinomio p1, polinomio p2, polinomio p3){

    int gradomax = max(p1.grado, max(p3.grado,p2.grado));

    polinomio res;

    res.grado = gradomax;
    res.coef = new double[gradomax + 1]{0};

    for(int i= 0; i<=gradomax; i++){

        if(i<=p1.grado){
            res.coef[i] += p1.coef[i];

        }
        if(i<=p2.grado){
            res.coef[i] += p2.coef[i];
        }

        if(i<=p3.grado){
            res.coef[i] += p3.coef[i];
        }
    }

    cout<<"La suma de los tres polinomios es: ";
    for(int i = gradomax; i>=0; i--){
        cout<<res.coef[i]<<"x^"<<i;
        if(i>0){
            cout<<" + ";
        }
    }
    delete[] res.coef;
    res.coef = nullptr;

}

void multiplicarpolinomio(polinomio p1,polinomio p2, polinomio p3){
    int gradomax = p1.grado + p2.grado + p3.grado;

    polinomio res;

    res.grado = gradomax;
    res.coef = new double[gradomax + 1];

    for(int i=0; i<=p1.grado; i++){
        for(int j=0; j<=p2.grado; j++){
            for(int z=0; z<=p3.grado;z++){
                
                res.coef[i+j+z] += p1.coef[i]*p2.coef[j]*p3.coef[z];
            }
        }
    }

    cout<<"El producto de los tres polinomios es: ";
     for(int i = gradomax; i>=0; i--){
        cout<<res.coef[i]<<"x^"<<i;
        if(i>0){
            cout<<" + ";
        }
    }

    delete[] res.coef;
    res.coef = nullptr;

}

void mostarpolinomio(polinomio p1, string nombre){

    cout<<"Polinomio "<<nombre<<" : ";

    for(int i = p1.grado; i>=0; i--){
        cout<<p1.coef[i]<<"x^"<<i;
        if(i>0){
            cout<<" + ";
        }
    }

}




int main(){

    polinomio p1,p2,p3;
    p1.grado = 2;
    p2.grado = 1;
    p3.grado = 2;

    p1.coef = new double [p1.grado + 1]{3,0,1};//los coeficientes van de menor a mayor exponente
    p2.coef = new double [p2.grado + 1]{5,-4};
    p3.coef = new double [p3.grado + 1]{1,0,3};

    mostarpolinomio(p1,"primero");
    cout<<endl;
    mostarpolinomio(p2, "segundo");
    cout<<endl;
    mostarpolinomio(p3, "tercero");
    cout<<endl;

    sumarpolinomio(p1,p2,p3);
    cout<<endl;
    multiplicarpolinomio(p1,p2,p3);
    cout<<endl;

    delete[]p1.coef;
    delete[]p2.coef;
    delete[]p3.coef;

    p1.coef = nullptr;
    p2.coef = nullptr;
    p3.coef = nullptr;

    return 0;
}