def quick_sort(arr, low, high):
    """
    Рекурсивная функция быстрой сортировки.
    """
    if low < high:
        # pi - индекс разбиения, arr[pi] находится на своём месте
        pi = partition(arr, low, high)

        # Рекурсивно сортируем элементы до и после разбиения
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def partition(arr, low, high):
    """
    Функция разбиения. Выбирает последний элемент как опорный.
    """
    # Выбираем последний элемент в качестве опорного
    pivot = arr[high]

    # Индекс для большего элемента (меньше которого будут элементы <= pivot)
    i = low - 1

    for j in range(low, high):
        # Если текущий элемент меньше или равен опорному
        if arr[j] <= pivot:
            i += 1 # Увеличиваем индекс меньшего элемента
            # Меняем arr[i] и arr[j]
            arr[i], arr[j] = arr[j], arr[i]

    # Поменять местами arr[i+1] и опорный элемент (arr[high])
    arr[i + 1], arr[high] = arr[high], arr[i + 1]

    # Возвращаем индекс, на котором теперь находится опорный элемент
    return i + 1

# Пример использования
if __name__ == "__main__":
    array = [10, 7, 8, 9, 1, 5]
    print("Исходный массив:", array)

    quick_sort(array, 0, len(array) - 1)

    print("Отсортированный массив:", array)
