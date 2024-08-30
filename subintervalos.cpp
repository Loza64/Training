#include <iostream>  
#include <vector>  
using namespace std;  

pair<int, pair<int, int>> encontrarSubintervaloMayor(const vector<int>& arr) {  
    int max_sum = arr[0];
    int current_sum = arr[0]; 
    int start = 0; 
    int end = 0;  
    int temp_start = 0; 

    for (int i = 1; i < arr.size(); i++) {  
        current_sum += arr[i];  


        if (current_sum > max_sum) {  
            max_sum = current_sum;  
            start = temp_start;  
            end = i;  
        }  

        if (current_sum < 0) {  
            current_sum = 0;  
            temp_start = i + 1; 
        }  
    }  

    return {max_sum, {start, end}}; 
}  

int main() {  
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};  
    auto resultado = encontrarSubintervaloMayor(arr);  
    
    cout << "La suma máxima es: " << resultado.first << endl;  
    cout << "El subintervalo mayor está entre los índices: " << resultado.second.first << " y " << resultado.second.second << endl;  

    return 0;  
}