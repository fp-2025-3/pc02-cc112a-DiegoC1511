#include<iostream>
#include<cstring>
using namespace std;

class cuentabancaria{

    private:

        int numerocuenta;
        char nombretitular[50];
        double saldo;
    
    public:

    cuentabancaria(){
        numerocuenta = 0;
        strcpy(nombretitular, "Desconocido");
        saldo = 0.0;
    }

    void crearcuenta(int numcuent, char nombretit[], double sald){
        numerocuenta = numcuent;
        strcpy(nombretitular, nombretit);
        saldo = sald;
    }

    void depositar(double monto){

        if(monto>0){
            saldo += monto;
            cout<<"DEPOSITO EXITOSO"<<endl;
        }else{
            cout<<"DEPOSITO NEGADO"<<endl;
        }
    }

    void retirar(double monto){
        if(monto>saldo){
            cout<<"SALDO INSUFICIENTE"<<endl;
        }
        if(monto>0){
            saldo -= monto;
            cout<<"RETIRO EXITOSO"<<endl;
        }else{
            cout<<"RETIRO NEGADO"<<endl;
        }
    }

    void mostrarinformacion(){
        cout<<"NUMERO CUENTA: "<<numerocuenta<<endl;
        cout<<"TITULAR: "<<nombretitular<<endl;
        cout<<"SALDO: "<<saldo<<endl;
    }


};

int main(){

    return 0;
}