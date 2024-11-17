#include <iostream>
#include <fstream>
#include <windows.h>


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

    // Вывод результата
    std::cout << "Текстовый вид орграфа:\n";
    
    for (int i = 0; i < n; ++i) {
        std::cout << i+1 << ":";    
        int edge_count = 0; 
        for (int j = 0; j < n; j++) {
           
            if (arr[i][j] == 1) {
                std::cout << j + 1 << " ";
                edge_count++;
            }           
        }

        if (edge_count == 0) {
            std::cout << "нет";  // Выводим "нет", если ни одной единицы не найдено
        }
        std::cout << std::endl;

    }

   

    // Очистка выделенной памяти
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
   

    return 0;
}
