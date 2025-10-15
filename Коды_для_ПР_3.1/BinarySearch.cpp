#include <iostream>
#include <vector>

// Функция бинарного поиска (итеративная реализация)
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0; // Левая граница поиска
    int right = arr.size() - 1; // Правая граница поиска

    while (left <= right) {
        int mid = left + (right - left) / 2; // Находим середину

        if (arr[mid] == target) {
            return mid; // Элемент найден, возвращаем индекс
        } else if (arr[mid] < target) {
            left = mid + 1; // Искомый элемент в правой половине
        } else { // arr[mid] > target
            right = mid - 1; // Искомый элемент в левой половине
        }
    }

    return -1; // Элемент не найден
}

int main() {
    std::vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int targetValue = 7;

    std::cout << "Ищем элемент " << targetValue << " в массиве: ";
    for (int num : sortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int resultIndex = binarySearch(sortedArray, targetValue);

    if (resultIndex != -1) {
        std::cout << "Элемент найден на позиции: " << resultIndex << std::endl;
    } else {
        std::cout << "Элемент не найден" << std::endl;
    }

    return 0;
}
