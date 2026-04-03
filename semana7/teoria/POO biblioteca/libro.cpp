#include "libro.h"
#include<iostream>
using namespace std;

libro::libro():titulo("desconocido"), autor("desconocido"), paginas(0), prestado(false){}
libro::libro( string t,string a, int p, bool pr): titulo(t), autor(a), paginas(p), prestado(false){}

libro::~libro(){}

string libro::gettitulo() const {

    return titulo;
}

string libro::getautor()const{

    return autor;
}

int libro::getpaginas()const{

    return paginas;
}

bool libro::getprestado()const{

    return prestado;
}


