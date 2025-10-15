#include <iostream>
#include <vector>

// Функция для сортировки массива методом вставок
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    // Проходим по всем элементам массива, начиная со второго
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Текущий элемент, который нужно вставить
        int j = i - 1;    // Индекс предыдущего элемента в отсортированной части

        // Перемещаем элементы arr[0..i-1], которые больше key, на одну позицию вперёд
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Сдвигаем элемент вправо
            j--;                 // Переходим к следующему элементу влево
        }
        arr[j + 1] = key; // Вставляем key на правильное место
    }
}

// Функция для вывода массива
void printArray(const std::vector<int>& arr) {
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};

    std::cout << "Исходный массив: ";
    printArray(arr);

    insertionSort(arr);

    std::cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}
