#include <iostream>
#include <climits>
#include <unistd.h>

using namespace std;

// Variables globales para almacenar el resultado final
int maxSum = INT_MIN;
int startIdx = -1;
int endIdx = -1;

void maxCrossingSum(int arr[], int left, int mid, int right)
{
    int sum = 0;
    int leftSum = INT_MIN;
    int start = mid;

    // Sumar desde el medio hacia la izquierda
    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            start = i; // Actualiza el inicio del subarreglo
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    int end = mid + 1;

    // Sumar desde el medio hacia la derecha
    for (int i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            end = i; // Actualiza el final del subarreglo
        }
    }

    // Actualiza el MaxSum si es mayor que el anterior
    if (leftSum + rightSum > maxSum)
    {
        maxSum = leftSum + rightSum;
        startIdx = start; // Actualiza inicio
        endIdx = end;     // Actualiza fin
    }

}

void maxSubArraySum(int arr[], int left, int right)
{
    if (left == right)
    {
        // Si somos un solo elemento
        if (arr[left] > maxSum)
        {
            maxSum = arr[left];
            startIdx = left;
            endIdx = left;
        }
        return;
    }

    int mid = (left + right) / 2;

    // Llama recursivamente para la mitad izquierda y derecha
    maxSubArraySum(arr, left, mid);
    maxSubArraySum(arr, mid + 1, right);

    // Encuentra la suma cruzada
    maxCrossingSum(arr, left, mid, right);
}

int main()
{
    // Define un arreglo simple
    int arr[] = {3, 4, 6, -2, -4, -6, -7, 1, 2, 4, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array size: " << n << endl;
    maxSubArraySum(arr, 0, n - 1);
    cout << "El máximo subarreglo tiene una suma de: " << maxSum
         << " desde el índice " << startIdx << " hasta el índice " << endIdx << endl;

    return 0;
}

//-----------------------Resumen grafico del flujo del codigo----------------------------
/*
maxSubArraySum(arr, 0, 12)  
├── maxSubArraySum(arr, 0, 6) (Suma máxima = 13)  
│   ├── maxSubArraySum(arr, 0, 3) (Suma máxima = 11)  
│   │   ├── maxSubArraySum(arr, 0, 1) (Suma máxima = 7)  
│   │   │   ├── maxSum en 3 (Caso base, valor = 3)  
│   │   │   └── maxSum en 4 (Caso base, valor = 4)  
│   │   └── maxSubArraySum(arr, 2, 3) (Suma máxima = 6)  
│   │       ├── maxSum en 6 (Caso base, valor = 6)  
│   │       └── maxSum en -2 (Caso base, valor = -2)  
│   └── maxSubArraySum(arr, 4, 6) (Suma máxima = -4)  
│       ├── maxSum en -4 (Caso base, valor = -4)  
│       ├── maxSum en -6 (Caso base, valor = -6)  
│       └── maxSum en -7 (Caso base, valor = -7)  
└── maxSubArraySum(arr, 7, 12) (Suma máxima = 20)  
    ├── maxSubArraySum(arr, 7, 9) (Suma máxima = 7)  
    │   ├── maxSum en 1 (Caso base, valor = 1)  
    │   └── maxSum en 2 (Caso base, valor = 2)  
    └── maxSubArraySum(arr, 10, 12) (Suma máxima = 13)  
        ├── maxSum en 5 (Caso base, valor = 5)  
        ├── maxSum en 7 (Caso base, valor = 7)  
        └── maxSum en 1 (Caso base, valor = 1)
*/