def fibonacci_search(arr, target):
    """
    Поиск по Фибоначчи элемента в отсортированном массиве.

    Args:
        arr: Отсортированный список элементов.
        target: Искомое значение.

    Returns:
        Индекс искомого элемента, если он найден, иначе -1.
    """
    n = len(arr)

    # 1. Найдем наименьшее число Фибоначчи, большее или равное n
    fib_m2 = 0  # (m-2)'е число Фибоначчи
    fib_m1 = 1  # (m-1)'е число Фибоначчи
    fib_m = fib_m2 + fib_m1  # m'ное число Фибоначчи

    while fib_m < n:
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m2 + fib_m1

    # 2. Смещение (offset) для отслеживания отброшенной части массива
    offset = -1

    # 3. Пока в массиве есть элементы для проверки
    while fib_m > 1:
        # Индекс кандидата для сравнения
        # i = min(offset + fib_m2, n - 1) - защищаемся от выхода за границы
        i = min(offset + fib_m2, n - 1)

        # 4. Если target больше, чем элемент в i, ищем в правой части
        if arr[i] < target:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i
        # 5. Если target меньше, ищем в левой части
        elif arr[i] > target:
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1
        # 6. Элемент найден
        else:
            return i

    # 7. Проверяем последний элемент (если остался)
    # Условие: fib_m1 > 0 гарантирует, что F(k-1) > 0, т.е. предыдущий шаг был возможен
    # offset + 1 < n проверяет, что индекс действителен
    # arr[offset + 1] == target проверяет сам элемент
    if fib_m1 and offset + 1 < n and arr[offset + 1] == target:
        return offset + 1

    # 8. Элемент не найден
    return -1

# Пример использования
if __name__ == "__main__":
    sorted_array = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
    target_value = 85

    print(f"Ищем элемент {target_value} в массиве: {sorted_array}")

    result_index = fibonacci_search(sorted_array, target_value)

    if result_index != -1:
        print(f"Элемент найден на позиции: {result_index}")
    else:
        print("Элемент не найден")
