#include <iostream>  

const int MAX_VERTICES = 100; // Número máximo de vértices en el grafo  

// Función para inicializar la matriz de adyacencia  
void inicializarMatriz(int matriz[MAX_VERTICES][MAX_VERTICES], int V) {  
    for (int i = 0; i < V; i++) {  
        for (int j = 0; j < V; j++) {  
            matriz[i][j] = 0; // Sin aristas  
        }  
    }  
}  

// Función para agregar una arista  
void agregarArista(int matriz[MAX_VERTICES][MAX_VERTICES], int v, int w) {  
    matriz[v][w] = 1; // Añadir arista de v a w  
    matriz[w][v] = 1; // Añadir arista de w a v (grafo no dirigido)  
}  

// Función para mostrar el grafo (matriz de adyacencia)  
void mostrarGrafo(int matriz[MAX_VERTICES][MAX_VERTICES], int V) {  
    std::cout << "Matriz de adyacencia del grafo:\n";  
    for (int i = 0; i < V; i++) {  
        for (int j = 0; j < V; j++) {  
            std::cout << matriz[i][j] << " ";  
        }  
        std::cout << "\n";  
    }  
}  

// Función para mostrar la información de los vértices y sus conexiones  
void mostrarInformacionGrafo(int matriz[MAX_VERTICES][MAX_VERTICES], int V) {  
    std::cout << "Información del grafo:\n";  
    for (int i = 0; i < V; i++) {  
        std::cout << "Vértice " << i << " está conectado a: ";  
        for (int j = 0; j < V; j++) {  
            if (matriz[i][j] == 1) {  
                std::cout << j << " ";  
            }  
        }  
        std::cout << "\n";  
    }  
}  

int main() {  
    int V = 5; // Número de vértices  
    int matriz[MAX_VERTICES][MAX_VERTICES];  

    // Inicializar la matriz de adyacencia  
    inicializarMatriz(matriz, V);  

    // Agregar aristas  
    agregarArista(matriz, 0, 1);  
    agregarArista(matriz, 0, 4);  
    agregarArista(matriz, 1, 2);  
    agregarArista(matriz, 1, 3);  
    agregarArista(matriz, 1, 4);  
    agregarArista(matriz, 2, 3);  
    agregarArista(matriz, 3, 4);  

    // Mostrar la matriz de adyacencia  
    mostrarGrafo(matriz, V);  
    
    // Mostrar información del grafo  
    mostrarInformacionGrafo(matriz, V);  

    return 0;  
}