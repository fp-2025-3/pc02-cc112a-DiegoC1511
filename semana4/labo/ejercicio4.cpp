#include<iostream>
#include<climits>
using namespace std;

int costominimo(int arr[], int n, int pos){

    if(pos == n){
        return 0;
    }
    
    int min = INT_MAX;
    int producto = 1;

    for(int i = pos; i<n; i++){
        producto *= arr[i];

        int costo = producto + costominimo(arr, n, i+1);

        if(costo < min){

            min = costo;
        }
    }

    return min;

}



int main(){

    int arr[15];
    int n;

    cout<<"ingrese el tamaño del arreglo: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"ingrese el "<<i+1<<"° elemento: ";
        cin>>arr[i];
    }

    int costomin = costominimo(arr, n, 0);

    cout<<"el costo minimo es: "<< costomin;

    return 0;
}