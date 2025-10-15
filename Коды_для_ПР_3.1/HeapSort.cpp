#include <iostream>
#include <vector>

// Функция для поддержания свойства кучи (max-heap)
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // левый = 2*i + 1
    int right = 2 * i + 2; // правый = 2*i + 2

    // Проверяем, существует ли левый дочерний элемент больший, чем корень
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Проверяем, существует ли правый дочерний элемент больший, чем корень
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если корень не является наибольшим, меняем местами и продолжаем heapify
    if (largest != i) {
        std::swap(arr[i], arr[largest]); // Меняем корень с largest
        heapify(arr, n, largest); // Применяем heapify к поддереву с корнем largest
    }
}

// Основная функция сортировки
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Построение max-heap из входного массива
    // Начинаем с последнего узла, у которого есть дочерние элементы (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень (максимальный элемент) в конец
        std::swap(arr[0], arr[i]);

        // Вызываем heapify для уменьшенной кучи (от 0 до i-1)
        heapify(arr, i, 0);
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
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Исходный массив: ";
    printArray(arr);

    heapSort(arr);

    std::cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}
