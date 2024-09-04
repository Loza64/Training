#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr = {1, 5, 7, 2, 3, 4, 6, 2, 4, 5, 2, 4, 5, 2, 5, 2};
    int n = arr.size();

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }else{
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
