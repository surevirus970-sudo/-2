def linear_search(arr, target):
    """
    Линейный поиск элемента в массиве.

    Args:
        arr: Список элементов.
        target: Искомое значение.

    Returns:
        Индекс искомого элемента, если он найден, иначе -1.
    """
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Элемент найден, возвращаем индекс
    return -1 # Элемент не найден

# Пример использования
if __name__ == "__main__":
    array = [3, 5, 2, 7, 9, 1, 4]
    target_value = 7

    print(f"Ищем элемент {target_value} в массиве {array}")

    result_index = linear_search(array, target_value)

    if result_index != -1:
        print(f"Элемент найден на позиции: {result_index}")
    else:
        print("Элемент не найден")
