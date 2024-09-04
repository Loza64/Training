#include<iostream>
using namespace std;

int main() {
    int x = 10;
    int* ptr = &x;     // ptr contiene la dirección de x
    int y = *&x;       // *&x es equivalente a x

    cout << "Valor de x: " << x << endl;  // Imprime: Valor de x: 10
    cout << "Valor de *&x: " << y << endl;  // Imprime: Valor de *&x: 10

    return 0;
}
