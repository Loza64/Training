#include<iostream>
using namespace std;

void funcion(int &dato){
    dato = 5;
}

int main(){
    int numero = 2;
    cout << "numero " << numero << endl;
    funcion(numero);
    cout << "numero modificado " << numero << endl;
    return 0;
}