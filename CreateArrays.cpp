#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{

    int n, m;
    cout << "Ingrese la cantidad de arreglos que desea crear: ";
    cin >> n;
    cout << "Ingrese la longitud que tendra cada arreglo: ";
    cin >> m;

    system("clear");
    vector<vector<int>> arr(n, vector<int>(m)); //int arr[n][m]

    for (int i = 0; i < n; i++)
    {
        cout << "------------------------------------------- " << i + 1 << "° arreglo" << " ---------------------------------------" << endl;
        for (int j = 0; j < m; j++)
        {
            cout << "Ingrese el " << j + 1 << "° dato del arreglo: ";
            cin >> arr[i][j];
        }
        system("clear");
    }

    system("clear");
    cout << "------------------------Arreglo bidimensional------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}