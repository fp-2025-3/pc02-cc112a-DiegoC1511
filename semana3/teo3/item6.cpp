#include <iostream>
#include <cstring>
using namespace std;

int my_strlen(const char* p){

    const char* str = p;

    while(*p != '\0'){

        p++;

    }

    return p - str;

}

char* my_strcpy(char* destino, const char* source){
    
    char* start = destino;

    while(*source != '\0'){

        *destino = *source;

        destino++;
        source++;
    }
    
    *destino = '\0';

    return start;

}

char* my_strcat(char* destination, const char* source){

    char* start = destination;

    while(*destination!= '\0'){

        destination ++;
        
    }
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

    return start;   
}    

int my_strcmp(char* a, char* b){

     int r1 = my_strlen(a);
     int r2 = my_strlen(b);

     if(r1<r2){
        return 1;
     }else if( r1>r2){
        return -1;
     }else{
        return 0;
     }


}

int main() {
    char texto[20] = "Hola";
    

    cout << strlen(texto) << endl;
    cout<< my_strlen(texto)<<endl;

    char destino[50];
    char source[] ="Fundamentos de la programacion";

    cout<<strcpy(destino, source)<<endl;
    cout<<my_strcpy(destino, source)<<endl;

    char destino1[50] = "Fundamentos";
    char destino2[50] = "Fundamentos";
    char source1[]= " de la programacion";

    cout<<strcat(destino1, source1)<<endl;
    cout<<my_strcat(destino2, source1)<<endl; 
    
    char pal1[] = "hola" ;
    char pal2[] = "hol";
    char pal3[] = "hola mundo";


    return 0;
}
