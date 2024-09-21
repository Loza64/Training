#include <iostream>  

int partition(int arr[], int low, int high) {  
    int pivot = arr[high]; // Elegir el último elemento como pivote  
    int i = (low - 1); // Índice del elemento más pequeño  

    for (int j = low; j <= high - 1; j++) {  
        // Si el elemento actual es menor o igual al pivote  
        if (arr[j] <= pivot) {  
            i++; // Incrementar el índice del elemento más pequeño  
            // Cambiar arr[i] y arr[j]  
            int temp = arr[i];  
            arr[i] = arr[j];  
            arr[j] = temp;  
        }  
    }  
    // Cambiar arr[i + 1] y arr[high] (o el pivote)  
    int temp = arr[i + 1];  
    arr[i + 1] = arr[high];  
    arr[high] = temp;  

    return (i + 1); // Retornar la posición del pivote  
}  

void quickSort(int arr[], int low, int high) {  
    if (low < high) {  
        // index es la posición del pivote  
        int index = partition(arr, low, high);  

        // Ordenar recursivamente los elementos antes y después del pivote  
        quickSort(arr, low, index - 1);  
        quickSort(arr, index + 1, high);  
    }  
}  

int main() {  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int arr_size = sizeof(arr) / sizeof(arr[0]);  

    quickSort(arr, 0, arr_size - 1);  

    std::cout << "Arreglo ordenado: \n";  
    for (int i = 0; i < arr_size; i++)  
        std::cout << arr[i] << " ";  
    std::cout << std::endl;  

    return 0;  
}