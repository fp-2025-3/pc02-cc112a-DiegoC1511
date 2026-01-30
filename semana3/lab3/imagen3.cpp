#include <iostream>
#include<cstring>
using namespace std;


int verificaranagrama(char* f1, char* f2){
    
    int k1 = strlen(f1);
    int k2 = strlen(f2);
    
    if(k1!=k2){
        return -1;
    }
    
    for(int i=0; i<k1-1; i++){
        
        for(int j=0; j<k1- 1-i; j++){
            
            if(*(f1 + j + 1) > *(f1 + j)){
                
                char temp = *(f1 + j);
                *(f1 + j) = *(f1 + j + 1);
                *(f1 + j + 1) = temp;
            }
        }
    }
    
    
    
    for(int i=0; i<k2-1; i++){
        
        for(int j=0; j<k2- 1-i; j++){
            
            if(*(f2 + j + 1) > *(f2 + j)){
                
                char temp = *(f2 + j);
                *(f2 + j) = *(f2 + j + 1);
                *(f2 + j + 1) = temp;
            }
        }
    }
    
    int k=0;
    bool ana = true;
    
    while(*(f1+k) != '\0'){
        
        if( *(f1 + k) == *(f2 + k)){
            ana = true;
        } else{
            ana = false;
            break;
        }
        
        k++;
    }
    
    if(ana == true){
        return 1;
    } else {
        return 0;
    }
    
    
}

int main(){
    
    char frase1[10];
    char frase2[10];
    
    cout<<"ingrese la primera palabra :";
    cin>>frase1;
    
    cout<<"ingrese la segunda palabra: ";
    cin>>frase2;
    
    if( verificaranagrama(frase1, frase2) == -1){
        cout<<"no es un anagrama";
    }else if( verificaranagrama(frase1, frase2) == 1){
        cout<<"es un anagrama";
    }else if (verificaranagrama(frase1, frase2) == 0){
        cout<<"no es un anagrama";
    }
    
    

    return 0;
}