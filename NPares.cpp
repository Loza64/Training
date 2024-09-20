#include <iostream>

using namespace std;

int NPares(int n, int arr[], int item)
{
    if (item > n)
    {
        return 1;
    }

    if (arr[item] % 2 == 0)
    {
        return arr[item] * NPares(n, arr, item + 1);
    }
    
    return NPares(n, arr, item + 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n = 3;
    int resultado = NPares(n, arr, 0);
    cout << "La multiplicacion de todos los pares es: " << resultado;
    return 0;
}