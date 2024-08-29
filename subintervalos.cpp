#include <iostream>  
using namespace std;  

int main() {  
    int array[] = {1, 2, 3, -2, 5, -1, 2, -3, 4, 6, -1, 2};  
    int n = sizeof(array) / sizeof(array[0]);  //Arrays lengh
    
    int max_sum = array[0]; 
    int current_sum = array[0];

    for (int i = 1; i < n; ++i) {  
        current_sum = max(array[i], current_sum + array[i]); 
        max_sum = max(max_sum, current_sum);
    }  

    cout << "El subintervalo maximo es: " << max_sum << endl;  
    return 0;  
}
