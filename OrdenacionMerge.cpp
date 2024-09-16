#include <iostream>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            std::cout << "L[i] es: " << L[i] << " y es menor o igual a: " << R[j] << " el item a guardar  en el arreglo es: " << L[i] << "\n";
            arr[k] = L[i];
            i++;
        }
        else
        {
            std::cout << "L[i] es: " << L[i] << " y es mayor a: " << R[j] << " el item a guardar  en el arreglo es: " << R[j] << "\n";
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        std::cout << "item i es: " << i << " y es menor al item: " << n1 << " el item a guardar en el arreglo L es: " << L[i] << "\n";
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        std::cout << "item j es: " << j << " y es menor al item: " << n2 << " el item a guardar en el arreglo R es: " << R[j] << "\n";
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {3, 4, 6, -2, -4, -6, -7, 1, 2, 4, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}