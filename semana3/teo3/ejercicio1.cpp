#include<iostream>
using namespace std;

int my_strcmp(const char* a, const char* b) {
    while (*a && *b) {
        if (*a != *b)
            return *a - *b;  
        a++;
        b++;
    }
    
    return *a - *b;
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

void ordenaralfabeticamente( char nombres[][20], int n){
    
    char temp[20];

    for(char (*i)[20] = nombres; i < nombres + n -1; i++){
        for(char(*j)[20] = nombres; j < nombres +n - 1 - ( i- nombres ); j++){

            if(my_strcmp(*j, *(j +1))>0){
                my_strcpy(temp, *j);
                my_strcpy(*j, *(j +1));
                my_strcpy(*(j +1), temp);
            }

        }

        
    }

}

int main(){

    char nombres[][20] = {"Americo", "Xingbeck", "William","Julio","Darwin", "Kevin"};

    int n = 6;

    ordenaralfabeticamente(nombres, n);

    for(char (*i)[20] = nombres; i< nombres + n; i++){
        cout<<*i<<" ";
    }

    return 0;
}
