import java.util.Arrays;

public class MergeSort {

    // Основной метод сортировки
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            // Находим середину
            int mid = left + (right - left) / 2;

            // Рекурсивно сортируем левую половину
            mergeSort(arr, left, mid);

            // Рекурсивно сортируем правую половину
            mergeSort(arr, mid + 1, right);

            // Сливаем отсортированные половины
            merge(arr, left, mid, right);
        }
    }

    // Метод для слияния двух отсортированных подмассивов
    private static void merge(int[] arr, int left, int mid, int right) {
        // Размеры временных подмассивов
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Создаём временные подмассивы
        int[] leftArr = new int[n1];
        int[] rightArr = new int[n2];

        // Копируем данные в временные подмассивы
        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }

        // Индексы для прохода по подмассивам и основному массиву
        int i = 0, j = 0, k = left;

        // Слияние подмассивов обратно в arr[left...right]
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) { // <= обеспечивает стабильность
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Копируем оставшиеся элементы из leftArr (если есть)
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        // Копируем оставшиеся элементы из rightArr (если есть)
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    public static void main(String[] args) {
        int[] array = {38, 27, 43, 3, 9, 82, 10};

        System.out.println("Исходный массив: " + Arrays.toString(array));

        mergeSort(array, 0, array.length - 1);

        System.out.println("Отсортированный массив: " + Arrays.toString(array));
    }
}
