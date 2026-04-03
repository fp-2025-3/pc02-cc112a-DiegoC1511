#include<iostream>
#include<fstream>
using namespace std;

class figuras{

private:    
    string nombre;
    double* rgb;

public:
    
    figuras(string nom, double r, double g, double b): nombre(nom){

        rgb = new double[3];
        rgb[0] = r;
        rgb[1] = g;
        rgb[2] = b;
    }

    figuras(const figuras &otro): nombre(otro.nombre){
        rgb = new double[3];
        for(int i=0; i<3; i++){
            rgb[i]=otro.rgb[i];
        } 
    }

    figuras& operator=(const figuras &otro){
        if(this != &otro){

            nombre = otro.nombre;

            delete[]rgb;

            rgb = new double[3];

            for(int i=0; i<3;i++){
                rgb[i] = otro.rgb[i];
            }

        }

        return *this;
    }

    virtual ~figuras(){
        delete[] rgb;
    }

    
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual void mostrar() const =0;

    string getNombre() const { return nombre; }
    double getr() const { return rgb[0]; }
    double getg() const { return rgb[1]; }
    double getb() const { return rgb[2]; }

};

class ciruculo: public figuras{

    private:

double radio;

public:

    ciruculo(string n, double r, double g, double b, double ra):figuras(n,r,g,b), radio(ra){}

    double area() const override{
        return 3.1416*radio*radio;

    }

    double perimetro() const override{
        return 2*3.1416*radio;
    }

    void mostrar() const override{
        cout<<"Figura: "<<getNombre()<<"[circulo]"<<endl;
        cout<<"Color RGB: ("<< getr() <<", "<<getg()<<", "<<getb()<<")"<<endl;
        cout<<"Radio: "<<radio<<" | Area: "<<area()<<" | Perimetro: "<<perimetro()<<endl;
        cout<<"---------------------------------"<<endl;
    }

};

class rectangulo: public figuras{

private:
    double base;
    double altura;

public:
    
    rectangulo(string n, double r, double g, double b, double base, double altura): figuras(n,r,g,b), base(base), altura(altura){}

    double area() const override{
        return base*altura;

    }

    double perimetro() const override{
        return 2*(base + altura);
    }

    void mostrar() const override{
        cout<<"Figura: "<<getNombre()<<"[rectangulo]"<<endl;
        cout<<"Color RGB: ("<<getr()<<", "<<getg()<<", "<<getb()<<")"<<endl;
        cout<<" Area: "<<area()<<" | Perimetro: "<<perimetro()<<endl;
        cout<<"---------------------------------"<<endl;
    }

};

class gestorfiguras{

    private:

    figuras** figura;
    int cantidad;
    int capacidad;

    void redimensionar(){
        capacidad *= 2; 
        figuras** nuevoarreglo = new figuras*[capacidad];

        for(int i=0; i<cantidad; i++){
            nuevoarreglo[i] = figura[i];

        }
        delete[] figura;

        figura = nuevoarreglo;

    }

    public:

    gestorfiguras(): cantidad(0), capacidad(2){
        figura = new figuras*[capacidad];
    }

    ~gestorfiguras(){
        for(int i=0; i<cantidad; i++){
            delete figura[i];
        }

        delete[] figura;
    }

    void agregarfiguras(figuras* nuevafigura){
        if(cantidad==capacidad){
            redimensionar();
        }
        figura[cantidad++] = nuevafigura;
    }

    void mostrartodas()const{
        for(int i=0; i<cantidad; i++){
            figura[i]->mostrar();
        }
    }

    double calcularareatotal(){
        double areatotal=0;
        for(int i=0; i<cantidad; i++){
            
            areatotal+=figura[i]->area();

        }
        return areatotal;
    }

    void guardarenarchivo(){
        ofstream archivo("figuras.txt");

        if(!archivo){
            cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
            return;
        }

        

        archivo<<"----REPORTE FIGURAS GEOMETRICAS----"<<endl;
        archivo<<endl;
        for(int i=0; i<cantidad; i++){
            archivo<<"Figura "<<i+1<<": "<<endl;
            archivo<<"Nombre: "<<figura[i]->getNombre()<<endl;
            archivo<<"Area: "<<figura[i]->area()<<endl;
            archivo<<"Perimetro: "<<figura[i]->perimetro()<<endl;
            archivo<<"Color: "<<"("<<figura[i]->getr()<<","<<figura[i]->getg()<<", "<<figura[i]->getb()<<")"<<endl;
            archivo<<"------------------------------------------------------"<<endl;

        }

        archivo<<"Area total: "<<calcularareatotal()<<endl;
        archivo.close();

    }

};

int main(){

    gestorfiguras miplano;

    miplano.agregarfiguras(new ciruculo("Sol", 255, 255, 0, 10.5));
    miplano.agregarfiguras(new rectangulo("Cancha", 0, 255, 0, 20.0, 10.0));
    miplano.agregarfiguras(new ciruculo("Moneda", 192, 192, 192, 2.0));
    miplano.agregarfiguras(new rectangulo("Libro", 0, 0, 255, 5.0, 8.0));

    cout<<"--LISTADO DE FIGURAS EN EL PLANO--"<<endl;

    miplano.mostrartodas();

    cout<<"Area total de las figuras: "<<miplano.calcularareatotal()<<endl;

    cout<<"Genrando archivo: "<<endl;
    miplano.guardarenarchivo();
    cout<<"Proceso finalizado"<<endl;


    return 0;
}

