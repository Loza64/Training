#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <climits>

using namespace std;

// Función para encontrar el máximo subarreglo cruzado
tuple<int, int, int> maxCrossingSum(const vector<int> &arr, int left, int mid, int right)
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

    return make_tuple(leftSum + rightSum, start, end);
}

tuple<int, int, int> maxSubArraySum(const vector<int> &arr, int left, int right)
{
    if (left == right)
    {
        return make_tuple(arr[left], left, right);
    }

    int mid = (left + right) / 2;

    auto [leftMax, leftStart, leftEnd] = maxSubArraySum(arr, left, mid);
    auto [rightMax, rightStart, rightEnd] = maxSubArraySum(arr, mid + 1, right);
    auto [crossMax, crossStart, crossEnd] = maxCrossingSum(arr, left, mid, right);

    if (leftMax >= rightMax && leftMax >= crossMax)
    {
        return make_tuple(leftMax, leftStart, leftEnd);
    }
    else if (rightMax >= leftMax && rightMax >= crossMax)
    {
        return make_tuple(rightMax, rightStart, rightEnd);
    }
    else
    {
        return make_tuple(crossMax, crossStart, crossEnd);
    }
}

int main()
{
    vector<int> arr = {3, 4, 6, 2 - 4 - 6 - 7, 1, 2, 4, 5, 7, 1};
    int n = arr.size();
    auto [maxSum, start, end] = maxSubArraySum(arr, 0, n - 1);
    cout << "El máximo subarreglo tiene una suma de: " << maxSum
         << " desde el índice " << start << " hasta el índice " << end << endl;
    return 0;
}