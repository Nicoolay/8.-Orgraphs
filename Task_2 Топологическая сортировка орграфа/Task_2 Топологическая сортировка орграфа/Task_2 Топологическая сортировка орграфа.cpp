#include <iostream>
#include <fstream>
#include <windows.h>

void dfs(int** arr, int vertex, bool* visited,  int* order, int& orderIndex, int n) {
    // Отмечаем текущую вершину как посещенную 
    visited[vertex] = true;

    // Проходим по всем вершинам, смежным с текущей
    for (int i = 0; i < n; ++i) {
        if (arr[vertex][i] == 1 && !visited[i]) {
            dfs(arr,i, visited, order, orderIndex,n);
        }      

    }
    order[orderIndex--] = vertex;
   }
int* top_sort(int** arr, bool* visited, int n) {
    int* order = new int[n];
    int orderIndex = n - 1;


    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(arr, i, visited, order, orderIndex, n);
        }
    }
    return order;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream input_file("input.txt");
    int n;
    input_file >> n;
    if (!input_file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    // Создание двумерного массива для графа
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    // Чтение значений в двумерный массив из файла
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input_file >> arr[i][j];
        }
    }
    input_file.close();
    bool* visited = new bool[n];
    // Инициализируем массив посещенных вершин значениями false
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }

    int* order = top_sort(arr,visited, n);

    std::cout << "Топологический порядок: ";
    for (int i = 0; i < n; ++i) {
        std::cout << (order[i]+1) << " ";
    }

    // Очистка выделенной памяти
       delete[] order; 

   for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;


    return 0;
}
