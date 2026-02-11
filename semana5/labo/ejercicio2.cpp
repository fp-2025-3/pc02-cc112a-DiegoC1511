#include<iostream>
#include<cmath>
using namespace std;

struct punto{
    double x;
    double y;
    double z;
};

double calculardistancia(punto a, punto b){

    double distancia;

    distancia = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)+ pow(b.z - a.z, 2));

    return distancia;

}

int main(){

    punto a;
    punto b;

    cout<<"ingrese las coordenadas del primer numero: "<<endl;;
    cout<<"X: ";
    cin>>a.x;
    cout<<"Y: ";
    cin>>a.y;
    cout<<"Z: ";
    cin>>a.z;
    cout<<endl;
    cout<<"ingrese las coordenadas del segundo numero: "<<endl;
    cout<<"X: ";
    cin>>b.x;
    cout<<"Y: ";
    cin>>b.y;
    cout<<"Z: ";
    cin>>b.z;

    cout<<"La distancia es: "<<calculardistancia(a,b);


    return 0;
}