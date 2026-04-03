#ifndef libro_h
#define libro_h
#include<string>

class libro {


private:
    std::string autor;
    std::string titulo;
    int paginas;
    bool prestado;

public:
    
    libro();
    libro(std::string a, std::string t, int p, bool pr);
    
    
    ~libro();


    std::string gettitulo() const;
    std::string getautor()const;
    int getpaginas()const;
    bool getprestado()const;

    void prestar();
    void devolver();

    void mostrarinfo();
    

};

#endif